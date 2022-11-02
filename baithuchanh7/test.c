#include <stdio.h>

int main() {
    int n, at[100], bt[100];
    readFromFile(&n, &at, &bt);
    printf("%d\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("%d %d\n", at[i], bt[i]);
    }
    
}