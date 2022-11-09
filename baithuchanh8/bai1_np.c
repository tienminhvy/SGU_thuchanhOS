#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/errno.h>
#define FIFO1 "/tmp/ff.1"
#define FIFO2 "/tmp/ff.2"
#define PM 0666
extern int errno;
#define PIPE_BUF 4096
int tinhGiaiThua(int n) {
    if (n <= 1) return 1;
    return n*tinhGiaiThua(n-1);
}
int main(int argc, char* argv[])
{
    int childpid, readfd, writefd;
    //kiểm tra 2 file FIFO1 và FIFO2 có khởi tạo thành công?
    if((mknod(FIFO1, S_IFIFO | PM, 0)<0)&&(errno!=EEXIST)){
        printf("Fail to create FIFO 1. Aborted.\n");
        return -1;
    }
    if((mknod(FIFO2, S_IFIFO | PM, 0)<0)&&(errno!=EEXIST)){
        unlink(FIFO1);
        printf("Fail to create FIFO 2. Aborted.\n");
        return -1;
    }
    childpid=fork();
    if(childpid==0){ //child
        //kiểm tra có thể mở 2 file FIFO1, FIFO2
        if((readfd=open(FIFO1, 0))<0)
        perror("Child cannot open readFIFO.\n");
        if((writefd=open(FIFO2, 1))<0)
        perror("Child cannot open writeFIFO.\n");
        //xử lý chương trình.
        int tam, giaiThua;
        read(readfd, &tam, sizeof(tam));
        giaiThua = tinhGiaiThua(tam);
        write(writefd, &giaiThua, sizeof(giaiThua));
        close(readfd);
        close(writefd);
        return 1;
    } else if(childpid>0) { //parent
        //Kiểm tra có mở thành công 2 file FIFO1, FIFO2.
        if((writefd=open(FIFO1, 1))<0)
        perror("Parent cannot open writeFIFO.\n");
        if((readfd=open(FIFO2, 0))<0)
        perror("Child cannot open readFIFO.\n");
        // xử lý chương trình.
        int n = atoi(argv[1]), ketQua;
        write(writefd, &n, sizeof(n));
        read(readfd, &ketQua, sizeof(ketQua));
        
        printf("%d! = %d\n", n, ketQua);

        while(wait((int*) 0)!=childpid);
            close(readfd);
        close(writefd);
        if(unlink(FIFO1)<0)
            perror("Cannot remove FIFO1.\n");
        if(unlink(FIFO2)<0)
            perror("Cannot remove FIFO2.\n");
        return 1;
    } else { printf("Fork failed\n"); return -1;}
}