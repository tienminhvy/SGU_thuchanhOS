#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    while(1) {
        printf("Test\n");
        sleep(1);
    }
}