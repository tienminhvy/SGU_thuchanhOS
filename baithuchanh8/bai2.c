#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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


int main(int argc, char ** argv) {
    char result[100];
    int fp1[2], fp2[2];
    int pid;
    if (argc < 4) {
        printf("Thieu doi so\n");
        return -1;
    }
    if (pipe(fp1) == 0 && pipe(fp2) == 0) {

        pid = fork();

        if (pid < 0) {
            printf("Fork failed!\n");
            return -1;
        } else if (pid == 0) {
            // than tien trinh con
            obj ObjTemp;
            int result;
            close(fp1[1]);
            read(fp1[0], &ObjTemp, sizeof(ObjTemp));
            result = tinhToan(ObjTemp.num1, ObjTemp.num2, ObjTemp.method);
            close(fp2[0]);
            write(fp2[1], &result, sizeof(result));
        } else {
            // than tien trinh cha
            int num1 = atoi(argv[1]), num2 = atoi(argv[2]);
            char method = argv[3][0];
            obj Obj;
            int kq;
            Obj.num1 = num1;
            Obj.num2 = num2;
            Obj.method = method;
            close(fp1[0]);
            write(fp1[1], &Obj, sizeof(Obj));
            close(fp2[1]);
            read(fp2[0], &kq, sizeof(kq));
            printf("%d %c %d = %d\n", Obj.num1, Obj.method, Obj.num2, kq);
            FILE *fp;
            fp = fopen("ketqua.txt", "w");
            fprintf(fp, "%d %c %d = %d", Obj.num1, Obj.method, Obj.num2, kq);
            fclose(fp);
        }
    } else {
        printf("Pipe failed!\n");
        return -2;
    }
}