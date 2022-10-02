#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid, ppid;

    pid = fork();
    if (pid == 0) {
        printf("ID tien trinh con: %d\n", getpid());
    } else if (pid > 0) {
        wait(NULL);
        printf("ID tien trinh cha: %d\n", getpid());
    } else printf("Khong the tao chuong trinh con voi ham fork.\n");
}