#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int countA(int a[]) {
    int count = 0;
    for(int i=9;i>=0;i--) if (a[i] != 0) count++;
    return count;
}

void printA(int a[]) {
    for(int i=9;i>=0;i--) 
    {
        if (a[i] != 0) printf(a[i]);
        else break;
    }
}

void producer(int a[]) {
    printf("Nhap n gia tri can dua vao: ");
    int n;
    scanf("%d", n);
    if (n > 10) {
        printf("n phai be hon 10\n");
    } else {
        printf("Nhap cac gia tri: ");
        for (int i = 9; i >= 0; i++) scanf("%d", &a[i]);
    }
}

void consumer(int a[]) {
    printf("Nhap n gia tri can lay ra: ");
    int n;
    scanf("%d", n);
    int ammount = countA(a);
    if (n > ammount) {
        printf("n phai be hon so luong gia tri trong hang cho\n");
    }
}

int main() {
    int a[10];

    for (int i = 0; i < 10; i++) a[i] = 0;
    
}