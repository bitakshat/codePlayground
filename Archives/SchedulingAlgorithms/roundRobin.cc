#include <bits/stdc++.h>

void round_robin_scheduling(int *bt, int *rbt, int tq, int n) {
    int count = 0, temp = 0, sq = 0, tat[n];
    bool done = false;
    int ix = 0;

    while (true) {
        for (; ix < n; ix++) {
            if (rbt[ix] == 0) {
                count++;
            }
            if (rbt[ix] > 0) rbt[ix] -= tq;
        }

        if (count == n) break;
    }

    std::cout << "\nRBT: ";
    for (int x = 0; x < n; x++) std::cout << rbt[x] << " ";
    std::cout << "\ncount: " << count << " ";
    std::cout << "\nSq: " << sq << " ";
}

int main(void) {

    int n = 0;
    std::cout << "Enter number of processes: ";
    std::cin >> n;

    int bt[n], tq, rbt[n];

    for (int ax = 0; ax < n; ax++) {
        std::cout << "Enter Burst Time of process p[" << ax+1 << "]: ";
        std::cin >> bt[ax];
        rbt[ax] = bt[ax];
    }

    std::cout << "Enter Time Quantum: ";
    std::cin >> tq;

    round_robin_scheduling(bt, rbt, tq, n);

    
    return 0;
}