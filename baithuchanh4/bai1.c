#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    while (1) {
        printf("while loop\n");
        sleep(1);
    }
}