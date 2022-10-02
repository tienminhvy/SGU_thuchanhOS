#include <stdio.h>
#include <string.h>

int main(int argc, char * argv[]) {
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    if (strcmp(argv[3], "+") == 0)
        printf("Ket qua: %d\n", add(a,b));
    else if (strcmp(argv[3], "-") == 0)
        printf("Ket qua: %d\n", sub(a,b));
    else printf("Doi so truyen khong dung.\n");
}