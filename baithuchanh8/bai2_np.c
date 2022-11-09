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

int tinhToan(int num1, int num2, char method) {
    int result = 0;
    switch (method)
    {
    case '+':
        result = num1+num2;
        break;
    case '-':
        result = num1-num2;
        break;
    case '*':
        result = num1*num2;
        break;
    case '/':
        result = num1/num2;
        break;
    
    default:
        break;
    }
    return result;
}

typedef struct
{
    int num1;
    int num2;
    char method;
} obj;

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
        obj ObjTemp;
        int result;
        read(readfd, &ObjTemp, sizeof(ObjTemp));
        result = tinhToan(ObjTemp.num1, ObjTemp.num2, ObjTemp.method);
        write(writefd, &result, sizeof(result));
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
        
        int num1 = atoi(argv[1]), num2 = atoi(argv[2]), kq;
        char method = argv[3][0];
        obj Obj;
        Obj.num1 = num1;
        Obj.num2 = num2;
        Obj.method = method;

        write(writefd, &Obj, sizeof(Obj));
        read(readfd, &kq, sizeof(kq));
        
        printf("%d %c %d = %d\n", Obj.num1, Obj.method, Obj.num2, kq);

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