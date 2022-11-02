#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void readFromFile(int *n, int *at, int *bt, int *pid){
    FILE *f;
    f = fopen("input.txt", "r+");
    if (!f) {
        printf("Cannot read file!\n");
        exit(0);
    }
    fscanf(f, "%d", n);
    for (int i = 0; i < *n; i++)
    {
        fscanf(f, "%d %d", &at[i], &bt[i]);
        pid[i] = i;
    }
    printf("Read from file successfully!\n");
}

void print_gantt_chartToFile(FILE *f, int n, int *arrv, int *ser, int *turn, int *pid)
{
    int i, j;
    fprintf(f,"\n"); // Empty line
    fprintf(f,"          GANTT CHART          ");
    fprintf(f,"          ***********          \n");
    // print top bar
    fprintf(f, " ");
    for(i=0; i<n; i++) {
        for(j=0; j<ser[i]; j++) fprintf(f, "--");
        fprintf(f, " ");
    }
    fprintf(f,"\n|");
 
    // printing process id in the middle
    for(i=0; i<n; i++) {
        for(j=0; j<ser[i] - 1; j++) fprintf(f," ");
        fprintf(f,"P%d", pid[i]);
        for(j=0; j<ser[i] - 1; j++) fprintf(f," ");
        fprintf(f,"|");
    }
    fprintf(f,"\n ");
    // printing bottom bar
    for(i=0; i<n; i++) {
        for(j=0; j<ser[i]; j++) fprintf(f,"--");
        fprintf(f," ");
    }
    fprintf(f,"\n");
 
    // printing the time line
    fprintf(f,"0");
    for(i=0; i<n; i++) {
        for(j=0; j<ser[i]; j++) fprintf(f,"  ");
        if(turn[i] > 9) fprintf(f,"\b"); // backspace : remove 1 space
        fprintf(f,"%d", turn[i]);
    }
    fprintf(f,"\n");
}

void printToFile(int n, int *arrv, int *ser, int *start, int *finish, int *wait, int *turn, int *pid, double avgwait, double avgturn) {
    FILE *f;
    f = fopen("output.txt", "w+");
    if (!f) {
        printf("Cannot write file!\n");
        exit(0);
    }
    fprintf(f, "\n\t PROCESS ARRIVAL SERVICE START FINISH WAIT TURN \n");
    for(int i=0;i<n;i++)
    {
        fprintf(f, "\n\tP%d\t%d \t %d \t %d \t %d \t %d \t %d \n",pid[i] ,arrv[i],
        ser[i], start[i], finish[i],wait[i],turn[i]);
    }
    fprintf(f, "\n AVERAGE WAITING TIME = %f tu\n",avgwait);
    fprintf(f, "\n AVERAGE TURN AROUND TIME = %f tu\n", avgturn);
    print_gantt_chartToFile(f, n, arrv, ser, turn, pid);
    printf("Write to file successfully!\n");
}

void print_gantt_chart(int n, int *arrv, int *ser, int *turn)
{
    int i, j;
    puts(""); // Empty line
    puts("          GANTT CHART          ");
    puts("          ***********          ");
    // print top bar
    printf(" ");
    for(i=0; i<n; i++) {
        for(j=0; j<ser[i]; j++) printf("--");
        printf(" ");
    }
    printf("\n|");
 
    // printing process id in the middle
    for(i=0; i<n; i++) {
        for(j=0; j<ser[i] - 1; j++) printf(" ");
        printf("P%d", i);
        for(j=0; j<ser[i] - 1; j++) printf(" ");
        printf("|");
    }
    printf("\n ");
    // printing bottom bar
    for(i=0; i<n; i++) {
        for(j=0; j<ser[i]; j++) printf("--");
        printf(" ");
    }
    printf("\n");
 
    // printing the time line
    printf("0");
    for(i=0; i<n; i++) {
        for(j=0; j<ser[i]; j++) printf("  ");
        if(turn[i] > 9) printf("\b"); // backspace : remove 1 space
        printf("%d", turn[i]);
 
    }
    printf("\n");
}