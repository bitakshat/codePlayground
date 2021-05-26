#include <iostream>

int main(void) {
    int t, con;
    std::cin >> t;

    while (t--) {
        long long int n;
        std::cin >> n;
        while (n != 1) {
            if (n % 2 == 0) {
                con = 1;
                n /= 2;
            } else {
                n = 3 * n + 1;
            }
        }

        (con == 1) ? std::cout << "YES\n" : std::cout << "NO\n";
    }

    return 0;
}