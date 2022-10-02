#include <stdio.h>
struct ps {
    int tu;
    int mau;
};
int main() {
    struct ps ps1,ps2,phso;
    printf("Phan so thu nhat: \n");
    nhap(&ps1.tu, &ps1.mau);
    printf("Phan so thu hai: \n");
    nhap(&ps2.tu, &ps2.mau);
    cong(ps1.tu,ps1.mau,ps2.tu,ps2.mau,&phso.tu,&phso.mau);
    printf("Tong hai phan so: ");
    xuat(phso.tu,phso.mau);
    tru(ps1.tu,ps1.mau,ps2.tu,ps2.mau,&phso.tu,&phso.mau);
    printf("Hieu hai phan so: ");
    xuat(phso.tu,phso.mau);
    nhan(ps1.tu,ps1.mau,ps2.tu,ps2.mau,&phso.tu,&phso.mau);
    printf("Tich hai phan so: ");
    xuat(phso.tu,phso.mau);
    chia(ps1.tu,ps1.mau,ps2.tu,ps2.mau,&phso.tu,&phso.mau);
    printf("Thuong hai phan so: ");
    xuat(phso.tu,phso.mau);
    return 0;
}