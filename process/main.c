#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void info();

int main()
{
    int pid = 1; // gia tri khoi tao, khong can quan tam
    int i = 1;

    printf("Tien trinh A: \n");
    info();  // in id cua tien trinh A va cha cua no

    for( i = 1; i <= 2; i++)
    {
        if(pid != 0) // neu pid khac 0, hien pid dang la gia tri khoi tao =1
            pid = fork(); // tap tien trinh moi
        else break;

        if(i == 1 && pid == 0) // lan khoi tao dau tien o tien trinh A va tao tien trinh thanh cong
        { 
                
            printf("Tien trinh B: \n");
            info(); // in info tien trinh B

            int pid1 = 1; // gia tri khoi tao, khong can quan tam
            int j1;  

            for(j1 = 1; j1 <= 2; j1++)
            {
                if(pid1 != 0) // neu pid1 khac 0, hien pid1 dang la gia tri khoi tao
                    pid1 = fork(); // tao tien trinh moi trong tien trinh B
                else break;

                if(j1 == 1 && pid1 == 0) // lan khoi tao dau tien o tien trinh B va tao tien trinh thanh cong
                {
                    printf("Tien trinh D: \n");
                    info(); // in thong tin tien trinh D
                }
                if(j1 == 2 && pid1 == 0) // lan khoi tao thu hai o tien trinh B va tao tien trinh thanh cong
                {
                    printf("Tien trinh E: \n");
                    info(); // in thong tin tien trinh E
                }
                
                for(int w = 1; w <= 4; w++)
                    wait(NULL); // loi goi de doi tien trinh con hoan tat 
            }
        }

        if(i == 2 && pid == 0) // lan khoi tao thu hai o tien trinh A va tao tien trinh thanh cong
        {  
            printf("Tien trinh C: \n");
            info(); // in info tien trinh C

            int pid2 = fork(); // khoi tao tien trinh H
            if(pid2 == 0) // thanh cong => trong than tien trinh con H
            {
                printf("Tien trinh H: \n");
                info(); // in
            }

            wait(NULL); // doi cho tien trinh con hoan tat, doi cho tao xong o tien trinh B
        }
    }

    wait(NULL); // doi tat ca tao xong.
    return 0;
}

void info()
{
    printf("ID cua tien trinh hien tai la: %d \n", getpid()); // in id tien trinh hien tai
    printf("ID tien trinh cha cua tien trinh hien tai la: %d \n", getppid()); // in id tien trinh cha
}