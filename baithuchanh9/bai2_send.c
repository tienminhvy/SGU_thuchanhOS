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

int main(int argc, char **argv) {
    key_t key;
    int msgid;
    // ftok to generate unique key
    key = ftok(".", 1);

    msgid = msgget(key, 0666 | IPC_CREAT);
    message.mesg_type = 1;

    if (argc < 4) {
        printf("Thieu doi so!\n");
        return -1;
    }

    // current process
    message.num1 = atoi(argv[1]);
    message.num2 = atoi(argv[2]);
    message.method = argv[3][0];
    msgsnd(msgid, &message, sizeof(message), 0);
    msgrcv(msgid, &message, sizeof(message), message.mesg_type, 0);
    printf("%d %c %d = %d\n", message.num1, message.method, message.num2, message.result);
    msgctl(msgid, IPC_RMID, NULL);
    return 0;
}