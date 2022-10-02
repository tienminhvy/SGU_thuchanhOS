#include <stdio.h>
#include <stdlib.h>

int isNumber(char n[]) {
    int i = 0;
    if (n[0] == '-')
        i = 1;
    for(int j=i;n[j]!='\0';j++){
        if (!isdigit(n[j])) return 0;
    }
    return 1;
}

void printArr(int a[], int n) {
    for(int i=0;i<n;i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main(int argc, char * argv[]) {
    int n = 0;
    for(int i=1;i<argc;i++) {
        if (isNumber(argv[i])) n++;
    }
    int a[n], j=0;
    for(int i=1;i<argc;i++) {
        if (isNumber(argv[i])) a[j++] = atoi(argv[i]);
    }
    int t=0;
    for(int i = 0;i < n-1;i++)
        for(int j=i+1;j < n;j++) 
            if (a[i] > a[j]) {
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
    printf("Day tang la: ");
    printArr(a,n);
}