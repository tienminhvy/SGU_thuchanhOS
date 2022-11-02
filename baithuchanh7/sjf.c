#include<stdio.h>

void main() {
    int n,i,j,temp1,temp2,sum=0;
    int pro[10], arrv[10], ser[10], start[10], finish[10],
    wait[10], turn[10];
    float avgturn=0.0,avgwait=0.0; start[0]=0;
    // Read from terminal
    // printf("\n ENTER THE NO. OF PROCESSES:");
    // scanf("%d",&n);
    // for(i=0;i<n;i++) {
    //     printf("\n ENTER THE ARRIVAL TIME AND SERVICE TIME OF PROCESS %d:",i+1);
    //     scanf("%d%d",&arrv[i],&ser[i]); pro[i]=i;
    // }
    // Read from file
    readFromFile(&n, &arrv, &ser, &pro);
    for(i=0;i<n;i++) {
        for(j=0;j<n-i-1;j++) {
            if(ser[j]>ser[j+1]) {
                temp1=ser[j];
                ser[j]=ser[j+1];
                ser[j+1]=temp1;
                temp2=arrv[j];
                arrv[j]=arrv[j+1];
                arrv[j+1]=temp2;
            }
        }
    }
    for(i=0;i<n;i++) {
        sum=0;
        for(j=0;j<i;j++)
            sum=sum+ser[j];
        start[i]=sum;
    }
    for(i=0;i<n;i++) {
        finish[i]=ser[i]+start[i];
        wait[i]=start[i];
        turn[i]=ser[i]+wait[i];
    }
    for(i=0;i<n;i++) {
        avgwait +=wait[i] ;
        avgturn +=turn[i];
    }
    avgwait/=n;
    avgturn/=n;
    // Write to terminal
    // printf("\n\t PROCESS ARRIVAL SERVICE START FINISH WAIT TURN \n");
    // for(i=0;i<n;i++){
    //     printf("\n\tP%d\t%d \t %d \t %d \t %d \t %d \t %d \n",
    //     pro[i],arrv[i], ser[i], start[i], finish[i],wait[i],turn[i]);
    // }
    // printf("\n AVERAGE WAITING TIME = %f tu",avgwait);
    // printf("\n AVERAGE TURN AROUND TIME = %f tu\n" ,avgturn);
    // Write to file
    printToFile(n, arrv, ser, start, finish, wait, turn, pro, avgwait, avgturn);
    getc(stdin);
}