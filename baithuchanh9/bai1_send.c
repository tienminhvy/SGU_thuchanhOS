#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
// structure for message queue
struct mesg_buffer {
    long mesg_type;
    int n;
    int result;
} message;

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

    // current process
    struct mesg_buffer msgp;
    msgp.mesg_type = 1;
    message.n = atoi(argv[1]);
    if (message.n < 4) {
        printf("Doi so phai lon hon 3!\n");
        return -1;
    }
    msgsnd(msgid, &message, sizeof(message), 0);
    msgrcv(msgid, &msgp, sizeof(msgp), msgp.mesg_type, 0);
    printf("%d! = %d\n", message.n, msgp.result);

    msgctl(msgid, IPC_RMID, NULL);
    return 0;
}