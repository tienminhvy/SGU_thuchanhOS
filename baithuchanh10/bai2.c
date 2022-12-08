#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#define SIZE 1024

int main() {
    int *shm_1, *shm_2, shmid_1, shmid_2, k,pid;

    key_t key1, key2;
    key1 = ftok("./shm1", 0);
    key2 = ftok(".", 0);

    shmid_1 = shmget(key1, SIZE, IPC_CREAT | 0666);
    shmid_2 = shmget(key2, SIZE, IPC_CREAT | 0666);

    shm_1 = (int*) shmat(shmid_1, 0, 0);
    shm_2 = (int*) shmat(shmid_2, 0, 0);

    pid = fork();
    if(pid==0) { // child
        shm_1[0] = 10;
        int a[] = {9,7,6,4,5,8,1,2,3,0};
        for (int i = 0; i < shm_1[0]; i++)
        {
            shm_1[i+1] = a[i];
        }
        sleep(3);
        printf("Ket qua tong cac phan tu cua mang la: %d\n", shm_2[0]);

        shmctl(shmid_1, IPC_RMID, (struct shmid_ds*) 0);
        shmctl(shmid_2, IPC_RMID, (struct shmid_ds*) 0);
        return 0;
    } else if(pid >0) { // parent
        sleep(1);
        for (int i = 0; i < shm_1[0]; i++)
            shm_2[0] += shm_1[i+1];

        shmdt((void*) shm_1);
        shmdt((void*) shm_2);
        sleep(5);
        return 0;
    } else { perror("Fork failed."); return 4; }
    return 0;
}