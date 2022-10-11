#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid1 = fork();
    pid_t pid2 = fork();
    pid_t pid3 = fork();

    if (pid1 > 0) {
        printf("pid1: %d", pid1);
    }
    if (pid2 > 0) {
        printf("pid2: %d", pid2);
    }
    if (pid3 > 0) {
        printf("pid3: %d", pid3);
    }
}