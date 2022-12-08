#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
sem_t mutex;
int n;
void* thread1(void *arg) {
    // wait
    for (int i = 1; i < 12; i+=2)
    {
        while(1){
            sem_wait(&mutex);
            if (i==n) break;
            sem_post(&mutex);
        }
        printf("%d ", i);
        n++;
        sem_post(&mutex);
    }
    printf("\n");
}
void* thread2(void *arg) {
    // wait
    for (int i = 2; i < 12; i+=2)
    {
        while(1){
            sem_wait(&mutex);
            if (i==n) break;
            sem_post(&mutex);
        }
        printf("%d ", i);
        n++;
        sem_post(&mutex);
    }
}
int main() {
    sem_init(&mutex, 0, 1);
    pthread_t t1,t2;
    pthread_create(&t2,NULL,thread2,NULL);
    pthread_create(&t1,NULL,thread1,NULL);
    n=1;
    sem_post(&mutex);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    sem_destroy(&mutex);
    return 0;
}