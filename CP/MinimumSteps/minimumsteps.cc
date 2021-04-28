#include <iostream>

int solve(int k, int m, int n) {
    int step;
    while (k != m) {
        if (k < m) {
            k = k * n;
            step += 1;
        }
        else if (k - m >= 2) {
            k = k - 2;
            step += 1;
        }
        else {
            k = k - 1;
            step += 1;
        }
    }
    return step;
}

int main() {
    // running test cases
    int t;
    std::cin >> t;

    for (int i = 0; i < t; i++) {
        int k, m, n;
        std::cin >> k >> m >> n;
        int sol = solve(k, m, n);
        std::cout << sol << std::endl;
    }

    return 0;
}