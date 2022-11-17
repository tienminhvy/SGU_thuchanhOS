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

    FILE *fp;
    fp = fopen("input.txt", "r");
    if (!fp) {
        printf("Cannot open file!\n");
        exit(0);
    }
    struct arr arrs[10];
    // Đọc từ file
    fscanf(fp, "%d", &singleVal.numOfArrs);
    for (int i = 0; i < singleVal.numOfArrs; i++)
    {
        fscanf(fp, "%d", &arrsLength.n[i]);
        for (int j = 0; j < arrsLength.n[i]; j++)
        {
            fscanf(fp, "%d", &arrs[i].a[j]);
            arrs[i].mesg_type = 1;
        }
    }
    fclose(fp);
    // printf("p0: %d \n", message.numOfArrs);
    msgsnd(msgidstr1, &singleVal, sizeof(singleVal), 0);
    printf("%d\n", arrsLength.n[0]);
    msgsnd(msgidstr2, &arrsLength, sizeof(arrsLength.n), 0);

    msgctl(msgidstr1, IPC_RMID, NULL);
    msgctl(msgidstr2, IPC_RMID, NULL);
}