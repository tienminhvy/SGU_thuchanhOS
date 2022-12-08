#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define DATASIZE 128
#define NAME "/shm-memory"

/**
 * Họ và tên: Tiền Minh Vy
 * Mã số sinh viên: 3121410023
 * Số ĐTDĐ: 0889131775
*/

void thr4_func(int *a) {

    int sum=0;
    int size = a[0];
    for (int i = 1; i <= size; i++)
    {
        sum+=a[i];
    }
    printf("Ket qua tong cac so chia het cho 3 la: %d\n", sum);
}

int main(void)
{
    int fd;
    int *addr;
    const char memid[] = NAME;
    

    /* open memory file descriptor */
    fd = shm_open(memid, O_RDONLY, 0666);
    if (fd == -1) {
        perror("Can't open file descriptor");
        return 1;
    }

    /* map shared memory */
    addr = mmap(NULL, DATASIZE, PROT_READ, MAP_SHARED, fd, 0);
    if (addr == MAP_FAILED) {
      perror("Memory mapping failed");
      return 1;
    }

    /*
        Xu ly du lieu trong shared memory object
    */

    int numA[10];
    memcpy(numA, addr, sizeof(numA));

    thr4_func(numA);

    return 0;
}