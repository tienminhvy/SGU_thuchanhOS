#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
// structure for message queue
struct mesg_buffer {
    long mesg_type;
    int num1;
    int num2;
    char method;
    int result;
} message;

int tinhToan(int num1, int num2, char method) {
    int result = 0;
    switch (method)
    {
    case '+':
        result = num1+num2;
        break;
    case '-':
        result = num1-num2;
        break;
    case '*':
        result = num1*num2;
        break;
    case '/':
        result = num1/num2;
        break;
    
    default:
        break;
    }
    return result;
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
    msg.result = tinhToan(msg.num1, msg.num2, msg.method);
    msgsnd(msgid, &msg, sizeof(msg), 0);
    printf("Xu ly hoan tat.\n");
    exit(0);
    return 0;
}