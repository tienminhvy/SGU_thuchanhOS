#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
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

    struct mesg_buffer msg;
    msg.mesg_type = 1;

    msgrcv(msgid, &msg, sizeof(msg), msg.mesg_type, 0);
    msg.result = tinhGiaiThua(msg.n);
    msgsnd(msgid, &msg, sizeof(msg), 0);
    printf("Xu ly hoan tat.\n");
    return 0;
}