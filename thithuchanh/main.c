#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#define N 100
#define DATASIZE 128
#define NAME "/shm-memory"

/**
 * Họ và tên: Tiền Minh Vy
 * Mã số sinh viên: 3121410023
 * Số ĐTDĐ: 0889131775
*/

int a[N]; // Mang Du Lieu

int oddNum = 0; // Khoi tao so phan tu le

void *thr1_func(void *arg); // Khoi tao mang voi so ngau nhien
void *thr2_func(void *arg); // Chon lua phan tu le trong mang
void *thr3_func(void *arg); // Chon phan tu chia het cho 3

void Shm_Writer(int *even_no); // Ghi so phan tu chia het cho 3 vao shared memory object

int main(int argc, char* argv[])
{
    pthread_t tid1, tid2, tid3; 
    
    // Kiem tra doi so dong lenh neu nhap thieu
    /*
        Viet doan code kiem tra doi so dong lenh
    */

    if (argc < 2) {
        printf("Thieu doi so!\n");
        exit(0);
    }

    int numArr ; // so phan tu mang nhan tu doi so dong lenh

    numArr = atoi(argv[1]);

    // Khởi tạo struct;

    pthread_create(&tid1, NULL, thr1_func, &numArr); // thr1_func
    pthread_create(&tid2, NULL, thr2_func, &numArr); // thr2_func
    pthread_create(&tid3, NULL, thr3_func, &numArr); // thr3_func


    pthread_join(tid1, NULL); //thr1
    pthread_join(tid2, NULL); //thr2
    pthread_join(tid3, NULL); //thr3
    
    return 1;
}

void *thr1_func(void *arg) {
    time_t t;
    srand((unsigned) time(&t));

    int *num = (int *)arg;
    for(int i=0; i < *num; i++) a[i] = rand() % 100;
    pthread_exit(NULL);
}

void *thr2_func(void *arg) {
    // Chon ca phan tu le trong mang a
    int *num = (int *) arg;
    
    for (size_t i = 0; i < *num; i++)
        if (a[i] % 2 != 0) 
            oddNum++;
    
    printf("\nSo luong cac so le la: %d\n", oddNum);
    pthread_exit(NULL);
}

void *thr3_func(void *arg) {
    // Chon cac phan tu chia het cho 3    
    
    int *num = (int *) arg;

    int numA[N] = {0};
    int c=1;

    printf("Liet ke cac so chia het cho 3: \n");

    for (int i = 0; i < *num; i++)
        if (a[i] % 3 == 0) {
            printf("%d ", a[i]);
            numA[c++] = a[i];
            numA[0]++;
        }
    Shm_Writer(numA);
    printf("\n");
    pthread_exit(NULL);
}

void Shm_Writer(int *even_no) {
    int fd;   
    int *addr;
    // A file descriptor - memid contains the name of the memory-mapped descriptor
    const char memid[] = NAME;

    /* create shared memory file descriptor */
    if ( (fd = shm_open(memid, O_RDWR | O_CREAT, 0666)) == -1) {
      perror("Can't open memory fd");
      exit(1);
    }

	/* truncate memory to DATASIZE */
	if ( (ftruncate(fd, DATASIZE)) == -1 ) {
      perror("Can't truncate memory");
      exit(1);
    }

    // mapping the shared memory space
    // there's a total of six arguments to the memory mapping function, mmap()
    /* map memory using our file descriptor */
    addr = mmap(NULL, DATASIZE, PROT_WRITE, MAP_SHARED, fd, 0);    
   
    if (addr == MAP_FAILED) {
      perror("Memory mapping failed");
      exit(1);
    }

    /* copy data to memory */    
    memcpy(addr, even_no, sizeof(even_no)*sizeof(int));
    
    /* wait for enter */
    printf("\nHit enter when finished ");
    getchar();
    /* clean up */
    munmap(addr, DATASIZE);
    shm_unlink(memid);
}