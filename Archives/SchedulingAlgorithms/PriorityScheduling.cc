// Prob 3. Write a program to implement Priority CPU Scheduling

#include <bits/stdc++.h>

void print_table(int *bt, int *p, int *wt, int *tat, int *pr, int n) {
    puts("+-----+------------+------------------+-----------------+--------------+");
    puts("| PID | Burst Time | Process Priority | Turnaround Time | Waiting Time |");
    puts("+-----+------------+------------------+-----------------+--------------+");

    for (int i = 0; i < n; i++) {
        printf("| %2d  |     %2d     |    %8d      |        %2d       |      %2d      |\n"
               , p[i], bt[i], pr[i], tat[i], wt[i], wt[i]);
        puts("+-----+------------+--------------+-----------------+--------------+---+");
    }
}

int main(void) {
    std::ios_base::sync_with_stdio(true);
    // std::cin.tie(NULL);
    int bt[20],p[20],wt[20],tat[20],pr[20],i,j,n,pos,temp;
    int avg_wt,avg_tat, total;
    std::cout << "Enter Total Number of Process: ";
    std::cin >> n;
 
    std::cout << "Enter Burst Time and Priority of ";
    for (i = 0; i < n; i++) {
        std::cout << "Process P[" << i + 1 << "]\n";
        std::cout << "Burst Time: ";
        std::cin >> bt[i];
        std::cout << "Priority  : ";
        std::cin >> pr[i];
        p[i]=i+1;           //contains process number
    }
    std::cout << '\n';
    //sorting burst time, priority and process number in ascending order using selection sort
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }
 
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
 
    wt[0]=0;    //waiting time for first process is zero
    //calculate waiting time
    for (i = 1; i < n; i++) {
        wt[i]=0;
        for (j = 0;j < i; j++)
            wt[i]+=bt[j];
 
        total+=wt[i];
    }
 
    avg_wt=total/n;      //average waiting time
    total=0;
    std::cout << '\n';
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];     //calculate turnaround time
        total+=tat[i];
        // printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }
 
    print_table(bt, p, wt, tat, pr, n);

    avg_tat=total/n;     //average turnaround time
    printf("\n\nAverage Waiting Time=%d",avg_wt);
    printf("\nAverage Turnaround Time=%d\n",avg_tat);
 
    return 0;
}

// void print_gantt_chart(int *bt, int *p, int *wt, int *tat, int *pr, int n)
// {
//     int i, j;
//     int last = bt[n-1] + ( n == 1 ? 0 : wt[n-1]);
//     // printing top bar
//     printf(" ");
//     for (i = 0; i < n; i++) {
//         for (j = 0; j < bt[i]; j++) printf("--");
//         printf(" ");
//     }
//     printf("\n|");
//     // middle position
//     for (i = 0; i < n; i++) {
//         for (j = 0; j < bt[i]-1; j++) printf(" ");
//         printf("p%d", pr[i]);
//         for (j = 0; j < bt[i]-1; j++) printf(" ");
//         printf("|");
//     }
//     printf("\n ");
//     // bottom bar
//     for (i = 0; i < n; i++) {
//         for(j = 0; j < bt[i]; j++) printf("--");
//         printf(" ");
//     }
//     printf("\n");
 
//     // printing waiting time
//     int minus = 0;
//     for( i = 0; i < n; i++) {
//         if (wt[i] > 9) printf(" ");
//         printf("%d", wt[i]);
//         if (wt[i+1] > 9){
//           minus = 1;
//         }
//         if (i + 1 == n )  if (last > 9) minus = 1;
//         for (j = 0; j < bt[i]-minus; j++) printf("  ");
 
//     }
//     if (last > 9) printf(" ");
//     printf("%d\n", last);
// }