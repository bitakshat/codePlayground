// Prob 1. Write a program to implement FCFS CPU scheduling algorithm
#include <bits/stdc++.h>

void print_table(int *bt, int *at, int *tat, int *wt, int *rt, int size) {
    puts("+-----+------------+--------------+-----------------+--------------+---------------+");
    puts("| PID | Burst Time | Arrival Time | Turnaround Time | Waiting Time | Response Time |");
    puts("+-----+------------+--------------+-----------------+--------------+---------------+");

    for (int i = 0; i < size; i++) {
        printf("| %2d  |     %2d     |      %2d      |        %2d       |      %2d      |       %2d      |\n"
               , i, bt[i], at[i], tat[i], wt[i], rt[i]);
        puts("+-----+------------+--------------+-----------------+--------------+---------------+");
    }
}

void print_gantt_chart(int *bt, int *at, int *tat, int size, int *pid) {
    printf(" ");
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < bt[i]; j++) printf("--");
        printf(" ");
    }
    printf("\n|");
 
    // printing process id in the middle
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < bt[i] - 1; j++) printf(" ");
        printf("P%d", pid[i]);
        for(int j = 0; j < bt[i] - 1; j++) printf(" ");
        printf("|");
    }
    printf("\n ");  
    // printing bottom bar
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < bt[i]; j++) printf("--");
        printf(" ");
    }
    printf("\n");
 
    // printing the time line
    printf("0");
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < bt[i]; j++) printf("  ");
        if(tat[i] > 9) printf("\b"); // backspace : remove 1 space
        printf("%d", tat[i]);
    }

    printf("\n");
}

void fcfs(int *bt, int *at, int size, int *pid) {
    int wt[size] = {}, tat[size] = {}, rt[size] = {};
    float avg_tat = 0, avg_wt = 0, avg_rt = 0;
    // waiting Time calculation
    wt[0] = 0;
    for (int z = 1; z < size; z++) {
        wt[z] = 0;
        for (int j = 0; j < z; j++) {
            wt[z] += bt[j];
        }
    }

    // calculate average waiting time
    for (auto c: wt) avg_wt += c;

    std::cout << '\n';
    // turn around time calculation
    for (int y = 0; y < size; y++) {
        tat[y] = bt[y] + wt[y];
        avg_tat += tat[y];
    }

    // response time calculation
    rt[0] = 0;
    for (int x = 0; x < size; x++) {
        rt[x] = tat[x] - at[x];
        avg_rt += rt[x];
    }

    print_table(bt, at, tat, wt, rt, size);

    std::cout << "\n\n";
    puts("\t\t******** GANTT CHART ********\t\t");
    std::cout << "\n\n";
    print_gantt_chart(bt, at, tat, size, pid);
    
    std::cout << "\n\n";
    std::cout << "\t\tAverage Turn Around Time: " << avg_tat / size << "ms" << '\n';
    std::cout << "\t\tAverage Waiting Time    : " << avg_wt / size << "ms" << '\n';
    std::cout << "\t\tAverage Response Time   : " << avg_rt / size << "ms" << '\n';

    std::cout << "\n\n";
}

int main(void) {

    int n;
    std::cout << "Enter number of processes: ";
    std::cin >> n;

    int bt[n], at[n], pid[n];
    // input burst time
    for (int x = 0; x < n; x++) {
        pid[x] = x + 1;
        std::cout << "Enter Burst Time of Process P" << x+1 << ": ";
        std::cin >> bt[x];
    }
    // input arrival time
    for (int y = 0; y < n; y++) {
        std::cout << "Enter Arrival Time of Process P" << y+1 << ": ";
        std::cin >> at[y];
    }

    fcfs(bt, at, n, pid);

    return 0;
}