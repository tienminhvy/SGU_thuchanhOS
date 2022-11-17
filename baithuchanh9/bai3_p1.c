#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>

// structure for message queue
struct singleVal {
    long mesg_type;
    int numOfArrs;
    int arrIndexHaveMaxLength;
} singleVal;

struct arrsLength
{
    long mesg_type;
    int n[10];
} arrsLength;

struct arr
{
    long mesg_type;
    int a[10];
} arr;

int main() {
    key_t key1, key2;
    int msgidstr1, msgidstr2;

    // ftok to generate unique key
    key1 = ftok(".", 1);
    key2 = ftok(".", 1);

    msgidstr1 = msgget(key1, 0666 | IPC_CREAT);
    msgidstr2 = msgget(key2, 0666 | IPC_CREAT);
    
    singleVal.mesg_type = 1;
    arrsLength.mesg_type = 1;

    msgrcv(msgidstr1, &singleVal, sizeof(singleVal), singleVal.mesg_type, 0);
    printf("%d \n", singleVal.numOfArrs);
    printf("%d \n",sizeof(arrsLength));
    msgrcv(msgidstr2, &arrsLength, sizeof(arrsLength), arrsLength.mesg_type, 0);
    printf("%d \n", arrsLength.n[0]);
    printf("Xu ly hoan tat.\n");
    exit(0);
    return 0;
}