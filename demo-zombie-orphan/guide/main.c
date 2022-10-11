#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>

int main() {
    pid_t pid;
    pid = fork();
    if (pid > 0) {
        printf("hello %d\n", getpid());
        sleep(10);
        exit(0);
    } else if (pid == 0) {
        printf("child %d\n", getpid());
        exit(0);
    } else printf("error\n");
}