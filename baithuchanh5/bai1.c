#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

typedef struct{
    int n;
    int a[100];
    int avg;
    int min;
    int max;
} arr;

void* findAvg(void *ar);
void* findMax(void *ar);
void* findMin(void *ar);

int main(int argc, char* argv[]){
    arr a;
    int avg, max, min;
    a.n = argc-1;
    for (int i = 1; i < argc; i++) a.a[i-1] = atoi(argv[i]);

    pthread_t tid[3];
    pthread_create(&tid[0], NULL, findAvg, &a);
    pthread_join(tid[0], NULL);
    pthread_create(&tid[1], NULL, findMax, &a);
    pthread_join(tid[1], NULL);
    pthread_create(&tid[2], NULL, findMin, &a);
    pthread_join(tid[2], NULL);
    
    avg = a.avg;
    min = a.min;
    max = a.max;
    printf("Gia tri trung binh: %d\n", avg/a.n);
    printf("Gia tri nho nhat: %d\n", min);
    printf("Gia tri lon nhat: %d\n", max);
    pthread_exit(NULL);
    return 0;
}

void* findAvg(void *ar) {
    arr *a = (arr *)ar;
    a->avg=0;
    for (int i = 0; i < a->n; i++)
    {
        a->avg+=a->a[i];
    }
}

void* findMax(void *ar) {
    arr *a = (arr *)ar;
    a->max=-99999999;
    for (int i = 0; i < a->n; i++)
    {
        if (a->a[i] > a->max) a->max = a->a[i];
    }
}

void* findMin(void *ar) {
    arr *a = (arr *)ar;
    a->min=99999999;
    for (int i = 0; i < a->n; i++)
    {
        if (a->a[i] < a->min) a->min = a->a[i];
    }
}