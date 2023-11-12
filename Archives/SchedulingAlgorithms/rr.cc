#include <bits/stdc++.h>

int main(void) {
    int n;
    // std::cout << "Enter number of processes: ";
    std::cin >> n;

    int bt[n], tat[n], rbt[n], wt[n], tq, sq = 0, count = 0, temp = 0;

    for (int i = 0; i < n; i++) {
        // std::cout << "Enter Burst Time of Process p[" << i << "]: ";
        std::cin >> bt[i];
        rbt[i] = bt[i];
    }

    // std::cout << "\nEnter Time Quantum: ";
    std::cin >> tq;

    while (1) {
        for (int ix = 0; ix < n; ix++) {
            if (rbt[ix] == 0) count++;
            if (rbt[ix] == 1) tq = 1; else tq = 2;
            if (rbt[ix] > tq) rbt[ix] = rbt[ix] - tq;
            if (rbt[ix] > 0) temp = rbt[ix], rbt[ix] = 0;
            
            sq += tq;
            std::cout << "SQ: " << sq << '\n';
        }
        
        if (count == n) break;
    }

    // waitimg time 
    // wt[0] = 0;
    // for (int x = 1; x < n; x++) {
    //     wt[x] = 
    // }

    return 0;
}