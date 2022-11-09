#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char ** argv) {
    char result[100];
    int fp[2];
    int pid;
    if (argc < 2) {
        printf("Thieu doi so\n");
        return -1;
    }
    if (pipe(fp) == 0) {

        pid = fork();

        if (pid < 0) {
            printf("Fork failed!\n");
            return -1;
        } else if (pid == 0) {
            // than tien trinh con
            printf("Data from child: %s\n", argv[1]);
            close(fp[0]);
            write(fp[1], argv[1], strlen(argv[1]));
        } else {
            // than tien trinh cha
            close(fp[1]);
            read(fp[0], result, strlen(argv[1]));
            printf("Read from child: %s\n", result);
        }
    } else {
        printf("Pipe failed!\n");
        return -2;
    }
}