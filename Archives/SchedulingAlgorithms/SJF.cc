// Prob 2. Write a program to implement Shortest Job First Scheduling Algorithm

#include <bits/stdc++.h>

#define MAX_PROCESS 100
struct process {
    int pid;
    int burst_time;
    int waiting_time;
    int arrival_time;
    int turn_around_time;
    int response_time;
};
 
typedef struct process Process;
double average_waiting_time;
int total_waiting_time;
 
void sort_process_by_burst_time(Process p[], int n);
void calculate_waiting_time(Process p[], int n);
void calculate_turn_around_time(Process p[], int n);
void calculate_response_time(Process p[], int n);

void print_gantt_chart(Process p[], int n);
void print_table(Process p[], int size);

void print_table(Process p[], int size) {
    puts("+-----+------------+--------------+-----------------+--------------+---------------+");
    puts("| PID | Burst Time | Arrival Time | Turnaround Time | Waiting Time | Response Time |");
    puts("+-----+------------+--------------+-----------------+--------------+---------------+");

    for (int i = 0; i < size; i++) {
        printf("| %2d  |     %2d     |      %2d      |        %2d       |      %2d      |       %2d      |\n"
               , p[i].pid, p[i].burst_time, p[i].arrival_time, p[i].turn_around_time, p[i].waiting_time, p[i].response_time );
        puts("+-----+------------+--------------+-----------------+--------------+---------------+");
    }
}

int main() {
    Process p[MAX_PROCESS];
    int n;
    puts("SHORTEST JOB FIRST SCHEDULING ALGORITHM");
    puts("=======================================");
 
    std::cout << "Enter number of Processes: ";
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cout << "Enter burst time of Process: P[" << i+1 << "] : ";
        std::cin >> p[i].burst_time;
        // scanf("%d", &p[i].burst_time);
        p[i].pid = i+1;
    }
 
    for (int j = 0;  j < n; j++) {
        std::cout << "Enter Arrival time for process: P[" << j << "]: ";
        std::cin >> p[j].arrival_time;
        // scanf("%d", &p[j].arrival_time);
    }

    sort_process_by_burst_time(p, n);
    calculate_waiting_time(p, n);
    calculate_turn_around_time(p, n);
    calculate_response_time(p, n);
 
    average_waiting_time = (double) ( (double)total_waiting_time / (double) n );
 
    puts("");
    printf("Average Waiting Time: %.2lf\n",average_waiting_time);
    
    print_table(p, n);
    std::cout << '\n';
    puts("******** GANTT CHART ********");
    print_gantt_chart(p, n);
 
    return 0;
}
 
void sort_process_by_burst_time(Process p[], int n) {
    int i, j;
    Process temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-1-i; j++) {
            if (p[j].burst_time > p[j+1].burst_time) {
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
}
 
void calculate_waiting_time(Process p[], int n) {
    int i;
    total_waiting_time = 0;
    p[0].waiting_time = 0;
    for (i = 1; i < n; i++) {
        p[i].waiting_time = p[i-1].waiting_time + p[i-1].burst_time;
        total_waiting_time += p[i].waiting_time;
    }
}
 
void calculate_turn_around_time(Process p[], int n) {
    for (int z = 0; z < n; z++) {
        p[z].turn_around_time = p[z].burst_time + p[z].waiting_time;
    }
}

void calculate_response_time(Process p[], int n) {
    p[0].response_time = 0;
    for (int e = 1; e < n; e++) {
        p[e].response_time = p[e].turn_around_time - p[e].arrival_time;
    }
}

void print_gantt_chart(Process p[], int n)
{
    int i, j;
    int last = p[n-1].burst_time + ( n== 1 ? 0 : p[n-1].waiting_time);
    // printing top bar
    printf(" ");
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].burst_time; j++) printf("--");
        printf(" ");
    }
    printf("\n|");
    // middle position
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].burst_time-1; j++) printf(" ");
        printf("p%d", p[i].pid);
        for(j=0; j<p[i].burst_time-1; j++) printf(" ");
        printf("|");
    }
    printf("\n ");
    // bottom bar
    for (i = 0; i < n; i++) {
        for(j = 0; j < p[i].burst_time; j++) printf("--");
        printf(" ");
    }
    printf("\n");
 
    // printing waiting time
    int minus = 0;
    for( i = 0; i < n; i++) {
        if (p[i].waiting_time > 9) printf(" ");
        printf("%d", p[i].waiting_time);
        if (p[i+1].waiting_time > 9){
          minus = 1;
        }
        if (i + 1 == n )  if (last > 9) minus = 1;
        for (j= 0; j < p[i].burst_time-minus; j++) printf("  ");
 
    }
    if (last > 9) printf(" ");
    printf("%d\n", last);
}