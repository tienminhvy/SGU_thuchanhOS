#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/wait.h>
#include <unistd.h>
// structure for message queue
struct mesg_buffer {
    long mesg_type;
    int n;
    int result;
} message;

int tinhGiaiThua(int n) {
    if (n <= 1) return 1;
    return n*tinhGiaiThua(n-1);
}

int main(int argc, char **argv) {
    key_t key;
    int msgid;
    // ftok to generate unique key
    key = ftok(".", 1);
    msgid = msgget(key, 0666 | IPC_CREAT);
    message.mesg_type = 1;

    if (argc < 2) {
        printf("Thieu doi so!\n");
        return -1;
    }

    pid_t pid = fork();

    if (pid == 0) {
        // child process
        struct mesg_buffer msg;
        msg.mesg_type = 1;
        msgrcv(msgid, &msg, sizeof(msg), msg.mesg_type, 0);
        msg.result = tinhGiaiThua(msg.n);
        msgsnd(msgid, &msg, sizeof(msg), msg.mesg_type);
        exit(0);
    } else if (pid > 0) {
        // current process
        message.n = atoi(argv[1]);
        msgsnd(msgid, &message, sizeof(message), message.mesg_type);
        wait(NULL);
        msgrcv(msgid, &message, sizeof(message), message.mesg_type, 0);
        printf("%d! = %d\n", message.n, message.result);
    } else {
        printf("Fork error!\n");
        return -1;
    }
    msgctl(msgid, IPC_RMID, NULL);
    return 0;
}