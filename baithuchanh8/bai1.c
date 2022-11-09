#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int tinhGiaiThua(int n) {
    if (n <= 1) return 1;
    return n*tinhGiaiThua(n-1);
}

int main(int argc, char ** argv) {
    char result[100];
    int fp1[2], fp2[2];
    int pid;
    if (argc < 2) {
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
            int tam, giaiThua;
            close(fp1[1]);
            read(fp1[0], &tam, sizeof(tam));
            giaiThua = tinhGiaiThua(tam);
            close(fp2[0]);
            write(fp2[1], &giaiThua, sizeof(giaiThua));
        } else {
            // than tien trinh cha
            int n = atoi(argv[1]), ketQua;
            close(fp1[0]);
            write(fp1[1], &n, sizeof(n));
            close(fp2[1]);
            read(fp2[0], &ketQua, sizeof(ketQua));
            printf("%d! = %d\n", n, ketQua);
        }
    } else {
        printf("Pipe failed!\n");
        return -2;
    }
}