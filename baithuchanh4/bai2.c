#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child process %d\n", getpid());
        sleep(10);
        exit(0);
    } else if (pid > 0) {
        printf("Current process %d\n", getpid());
        sleep(5);
        exit(0);
    } else printf("error\n");
}