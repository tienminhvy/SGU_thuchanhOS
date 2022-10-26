#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>

// gcc bai3.c -o bai3 -pthread && ./bai3 source.txt target.txt

typedef struct
{
    char *fn1;
    char *fn2;
} file;

void *copyData(void *arg) {
    file *tmp = (file *)arg;
    char *s = malloc(255);
    FILE *fp1, *fp2;
    fp1 = fopen(tmp->fn1, "r");
    fp2 = fopen(tmp->fn2, "w");
    fseek(fp1, 0, SEEK_END);
    int size = ftell(fp1);
    fseek(fp1, 0, SEEK_SET);
    while (fgets(s, sizeof(s), fp1))
    {
        fputs(s, fp2);
    }
    fclose(fp1);
    fclose(fp2);
    printf("Da sao chep thanh cong %d ky tu\n", size);
}

int main(int argc, char **argv) {
    file fn;
    fn.fn1 = argv[1];
    fn.fn2 = argv[2];
    pthread_t tid;
    pthread_create(&tid, NULL, copyData, &fn);
    pthread_join(tid, NULL);
}