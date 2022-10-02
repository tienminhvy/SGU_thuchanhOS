#include <stdio.h>

void cong(int tu1, int mau1, int tu2, int mau2, int *tu, int *mau) {
    if (mau1 == mau2) {
        *mau = mau1;
        *tu = tu1+tu2;
    } else {
        *tu = tu1*mau2+tu2*mau1;
        *mau = mau1*mau2;
    }
}

void tru(int tu1, int mau1, int tu2, int mau2, int *tu, int *mau) {
    if (mau1 == mau2) {
        *mau = mau1;
        *tu = tu1-tu2;
    } else {
        *tu = tu1*mau2-tu2*mau1;
        *mau = mau1*mau2;
    }
}

void nhan(int tu1, int mau1, int tu2, int mau2, int *tu, int *mau) {
    *tu = tu1 * tu2;
    *mau = mau1 * mau2;
}

void chia(int tu1, int mau1, int tu2, int mau2, int *tu, int *mau) {
    *tu = tu1 * mau2;
    *mau = mau1 * tu2;
}