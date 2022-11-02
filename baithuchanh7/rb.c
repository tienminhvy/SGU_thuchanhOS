#include<stdio.h>

void main()
{
    int count=0,swt=0,stat=0,i,temp,sq=0;
    int pro[10],st[10],bt[10],wt[10],tat[10],n,tq;
    float atat=0.0,awt=0.0;
    printf("\n ENTER THE NO. OF PROCESSES:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\n ENTER THE SERVICE TIME OF PROCESS %d:",i);
        scanf("%d",&bt[i]);
        st[i]=bt[i];
        pro[i]=i;
    }
    printf("\n ENTER THE TIME QUANTUM:");
    scanf("%d",&tq);

    while(1)
    {
        for(i=0,count=0;i<n;i++)
        {
            temp=tq;
            if(st[i]==0)
            {
                count++;
                continue;
            }
            if(st[i]>tq)
                st[i]=st[i]-tq;
            else if(st[i]>=0)
            {
                temp=st[i];
                st[i]=0;
            }
            sq=sq+temp;
            tat[i]=sq;
        }
        if(count==n)
            break;
    }
    for(i=0;i<n;i++)
    {
        wt[i]=tat[i]-bt[i];
        stat=stat+tat[i];
        swt=swt+wt[i];
    }
    awt=(float)swt/n;
    atat=(float)stat/n;

    printf("\n PROCESS BURST TIME WAIT TURN \n");

    for(i=0;i<n;i++)
    {
        printf("\n\tP%d\t%d \t %d \t%d\n" ,
        pro[i],bt[i],wt[i],tat[i]);
    }

    printf("\n AVERAGE WAITING TIME = %f tu",awt);
    printf("\n AVERAGE TURN AROUND TIME = %f tu\n",atat);
    getc(stdin);
    }