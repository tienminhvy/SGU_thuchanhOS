#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <math.h>

int checkNT(int n) {
    if (n < 2) return 0;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return 0;
    return 1;
}

void *xuatSoNguyenTo(void *n) {
    int *num = (int *)n;
    printf("Cac so nguyen to nho hon hoac bang n: ");
    for (int i = 2; i <= *num; i++)
        if (checkNT(i)) printf("%d ", i);
    printf("\n");
}


int main(int argc, char* argv[]){
    int n = atoi(argv[1]);
    
    pthread_t tid;
    pthread_create(&tid, NULL, xuatSoNguyenTo, &n);
    pthread_exit(NULL);
    return 0;
}