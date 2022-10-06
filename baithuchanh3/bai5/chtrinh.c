#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int kiemTra(int n) {
    do {
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }
    } while (n>1);
    if (n==1) return 1;
    return 0;
}

void xuat(int n) {
    printf("%d ", n);
    do {
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }
        printf("%d ",n);
    } while (n>1);
    printf("\n");
}

int main(int argc, char **argv) {

    char *t = argv[1];
    for (int i=0;i<strlen(t);i++) {
        if ((t[i]>65) && (t[i]<122)) {
            printf("Doi so khong la so nguyen duong\n");
            return 0;
        }
    }
    int n = atoi(t);

    pid_t pid = fork();

    if (pid == 0) {

        xuat(n);

    } else if (pid > 0) {
        wait(NULL);
        if (kiemTra(n) == 1) {
            printf("Phong doan chinh xac\n");
        } else printf("Phong doan chua chinh xac\n");
    } else printf("Xay ra loi khi khoi tao tien trinh con bang fork\n");

}