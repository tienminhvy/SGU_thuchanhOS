#include <stdio.h>

int main(int argc, char *argv[])
{
    int re;
    printf("Call system to execute ls -a\n");
    re=system("ls -a");
    if(re != -1) 
        printf("System call ls is done!\n");
    printf("Call system to execute ps -a\n");
    re=system("ps -a");
    if(re != -1) 
        printf("System call ps is done!\n");
    return 0;
}