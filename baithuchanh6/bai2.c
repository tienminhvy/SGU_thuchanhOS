#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>

// gcc bai2.c -o bai2 -pthread && ./bai2 4 result.txt

void *thread1(void *arg);
void *thread2(void *arg);
void *thread3(void *arg);
typedef struct
{
    char **argv;
    int n;
    int giaiThua;
    int sum;
} strc;

int main(int argc, char **argv) {
    strc cauTruc;
    cauTruc.argv = argv;
    pthread_t tid1, tid2, tid3;
    pthread_create(&tid1, NULL, thread1, &cauTruc);
    pthread_join(tid1, NULL);
    pthread_create(&tid2, NULL, thread2, &cauTruc);
    pthread_join(tid2, NULL);
    pthread_create(&tid3, NULL, thread3, &cauTruc);
    pthread_join(tid3, NULL);
}

int giaiThua(int n) {
    if (n==0) return 1;
    return n*giaiThua(n-1);
}

void *thread1(void *arg) {
    strc *tmp = (strc *) arg;
    tmp->n = atoi(tmp->argv[1]);
    if (tmp->n > 0) {
        tmp->giaiThua = giaiThua(tmp->n);
    }
}

void *thread2(void *arg) {
    strc *tmp = (strc *) arg;
    int c = 0;
    tmp->sum = 0;
    while (c<=tmp->giaiThua)
    {
        if (c%2==0) tmp->sum+=c;
        c++;
    }
}

void *thread3(void * arg) {
    strc *tmp = (strc *) arg;
    FILE *fp;
    char *fileName = tmp->argv[2];
    fp = fopen(fileName, "w");
    fprintf(fp, "n = %d\n", tmp->n);
    fprintf(fp, "%d! = %d\n", tmp->n, tmp->giaiThua);
    fprintf(fp, "sum = %d", tmp->sum);
    fclose(fp);
    printf("Da tao ra tap tin %s\n", tmp->argv[2]);
}