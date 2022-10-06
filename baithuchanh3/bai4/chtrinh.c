#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {

    char *t = argv[1];
    for (int i=0;i<strlen(t);i++) {
        if ((t[i]>65) && (t[i]<122)) {
            printf("Doi so khong la so nguyen duong\n");
            return 0;
        }
    }
    int n = atoi(t);
    int tong=0;

    pid_t pid = fork();

    if (pid == 0) {

        for(int i=1;i<=n;i++) 
            if (n%i == 0) tong+=i;
        printf("Tong cac uoc so cua n: %d\n", tong);

    } else if (pid > 0) {
        wait(NULL);
        for(int i=1;i<=n;i++) tong+=i;
        printf("Tong tu 1 den n: %d\n", tong);
    } else printf("Xay ra loi khi khoi tao tien trinh con bang fork\n");
}