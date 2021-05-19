

#include <iostream>

void solve(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 2 * n; j++) {
            if (j <= i || j > 2 * n - i) {
                std::cout << "*";
            } else {
                std::cout << "#";
            }
        }
        std::cout << '\n';
    }
}

int main(void) {
    int t, n;
    std::cin >> t;
    while (t--) {
        std::cin >> n;
        solve(n);
    }
    return 0;
}