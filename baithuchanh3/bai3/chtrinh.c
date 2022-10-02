#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

void xuatThongTinTienTrinh(pid_t pid, char *s) {
    if (pid == 0) {
        printf("Tien trinh %s\n", s);
        printf("ID tien trinh con: %d\n", getpid());
        printf("ID tien trinh cha cua no: %d\n", getppid());
        printf("\n");
    } else {
        wait(NULL);
        printf("Tien trinh %s\n", s);
        printf("ID tien trinh: %d\n", getpid());
        printf("\n");
    }
}

int main() {
    pid_t pidAB, pidAC, pidBD, pidBE, pidCH;

    pidAB = fork();

    if (pidAB == 0) {
        xuatThongTinTienTrinh(pidAB, "B");

        pidBD = fork(); 

        if (pidBD == 0) {
            xuatThongTinTienTrinh(pidBD, "D");
        } else if (pidBD > 0) {
            
            wait(NULL);
            pidBE = fork();

            if (pidBE == 0) {
                xuatThongTinTienTrinh(pidBE, "E");
            }

        } else printf("Khong the tao chuong trinh con voi ham fork.\n");

    } else if (pidAB > 0) {
        wait(NULL);
        xuatThongTinTienTrinh(pidAB, "A");
        pidAC = fork();
        if (pidAC == 0) {
            xuatThongTinTienTrinh(pidAC, "C");

            pidCH = fork();

            if (pidCH == 0) {
                xuatThongTinTienTrinh(pidCH, "H");
            } else if (pidCH < 0) printf("Khong the tao chuong trinh con voi ham fork.\n");

        } else if (pidAC < 0) printf("Khong the tao chuong trinh con voi ham fork.\n");
    } else printf("Khong the tao chuong trinh con voi ham fork.\n");
}