#include <stdio.h>

struct hs {
    int nguyen;
    int tu;
    int mau;
};

void doiHonSo(int nguyen, int *tu, int mau) {
    *tu = nguyen * mau + (*tu);
}

void nhapHonSo(int *nguyen, int *tu, int *mau) {
    printf("Nhap phan nguyen: ");
    scanf("%d", nguyen);
    printf("Nhap tu: ");
    scanf("%d", tu);
    printf("Nhap mau: ");
    scanf("%d", mau);
}

int main() {
    struct hs honSo1, honSo2, honSo;
    printf("Hon so thu nhat: \n");
    nhapHonSo(&honSo1.nguyen, &honSo1.tu, &honSo1.mau);
    doiHonSo(honSo1.nguyen, &honSo1.tu, honSo1.mau);
    printf("Hon so thu hai: \n");
    nhapHonSo(&honSo2.nguyen, &honSo2.tu, &honSo2.mau);
    doiHonSo(honSo2.nguyen, &honSo2.tu, honSo2.mau);
    cong(honSo1.tu,honSo1.mau,honSo2.tu,honSo2.mau,&honSo.tu,&honSo.mau);
    printf("Tong hai hon so: ");
    xuat(honSo.tu,honSo.mau);
    tru(honSo1.tu,honSo1.mau,honSo2.tu,honSo2.mau,&honSo.tu,&honSo.mau);
    printf("Hieu hai hon so: ");
    xuat(honSo.tu,honSo.mau);
    nhan(honSo1.tu,honSo1.mau,honSo2.tu,honSo2.mau,&honSo.tu,&honSo.mau);
    printf("Tich hai hon so: ");
    xuat(honSo.tu,honSo.mau);
    chia(honSo1.tu,honSo1.mau,honSo2.tu,honSo2.mau,&honSo.tu,&honSo.mau);
    printf("Thuong hai hon so: ");
    xuat(honSo.tu,honSo.mau);
}