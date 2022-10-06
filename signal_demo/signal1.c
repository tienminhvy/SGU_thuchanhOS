#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void signal_han(int signal_no);
int f;

int main() {
    signal(2, signal_han);
    while(1) {
        if (f==1) break;
        printf("Test\n");
        sleep(1);
    }
}

void signal_han(int signal_no) {
    printf("Signal handler: %d", signal_no);
    f = 1;
}