#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>

// gcc bai1.c -o bai1 -pthread && ./bai1

typedef struct
{
    int a[100];
    int n;
} arr;

void *sort(void *arg) {
    arr *a = (arr *)arg;
    int t;
    for (int i = 0; i < (a->n)-1; i++)
        for (int j = i+1; j < a->n; j++)
            if (a->a[i] > a->a[j]) {
                t = a->a[i];
                a->a[i]=a->a[j];
                a->a[j] = t;
            }
}

void split(arr a, arr *a1, arr *a2) {
    a1->n = a.n/2;
    a2->n = a.n-a1->n;
    int c=0;
    for (int i=0;i<a1->n;i++)
        a1->a[i] = a.a[c++];
    for (int i=0;i<a2->n;i++) {
        a2->a[i] = a.a[c++];
    }
}

void merge(arr *a, arr a1, arr a2) {
    a->n = a1.n+a2.n;
    int c = 0;
    for (int i = 0; i < a1.n; i++)
        a->a[c++] = a1.a[i];
    for (int i = 0; i < a2.n; i++)
        a->a[c++] = a2.a[i];
}

void print(arr a) {
    printf("%d\n", a.n);
    for (int i = 0; i < a.n; i++)
    {
        printf("%d ", a.a[i]);
    }
    printf("\n");
}

void init(arr *a) {
    int arrInt[] = {14,7,9,3,4,5,6,2,1,10};
    int length = sizeof(arrInt)/sizeof(int);
    a->n = length;
    for (int i = 0; i < a->n; i++)
    {
        a->a[i] = arrInt[i];
    }
}
int main() {
    arr ar, ar1 ,ar2, arFinal;
    init(&ar);
    split(ar,&ar1,&ar2);
    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, sort, &ar1);
    pthread_create(&tid2, NULL, sort, &ar2);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    merge(&arFinal, ar1, ar2);
    print(arFinal);
}