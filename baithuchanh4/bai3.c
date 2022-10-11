#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int cmd1 = system("mkdir '/mnt/d/OneDrive - NVC/Desktop/BaiTap'");
    if (cmd1 != -1) {
        int cmd2 = system("mkdir '/mnt/d/OneDrive - NVC/Desktop/BaiTap/LyThuyet'");
        int cmd3 = system("mkdir '/mnt/d/OneDrive - NVC/Desktop/BaiTap/ThucHanh'");
        if (cmd2 != -1 && cmd3 != -1) {
            int cmd4 = system("touch '/mnt/d/OneDrive - NVC/Desktop/BaiTap/ThucHanh/test'");
            if (cmd4 != -1) printf("Hoan thanh\n");
        }
    }
}