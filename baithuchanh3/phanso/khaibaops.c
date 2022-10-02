#include <stdio.h>

void nhap(int *tu, int *mau) {
    printf("Nhap tu: ");
    scanf("%d", tu);
    printf("Nhap mau: ");
    scanf("%d", mau);
}

void xuat(int tu, int mau) {
    printf("%d/%d\n", tu, mau);
}