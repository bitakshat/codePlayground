#include <iostream>
#include <vector>

int magicFunction(int n) {
    long long int num, sum = 0, pos = 0;
    int min = 1;
    std::vector<long long int> nArray;

    while (n--) {
        std::cin >> num;
        nArray.push_back(num);
    }

    for (auto x : nArray) sum += x;  // calcualtes sum

    for (int i = 0; i < n; i++) {
        if ((sum - nArray[i]) % 7 == 0) {
            if (nArray[i] < min) {
                min = nArray[i];
                pos = i;
            }
        }
    }

    return -1 ? pos == 0 : pos;
}

int main(void) {
    int n;
    std::cin >> n;

    int sol = magicFunction(n);
    std::cout << sol << '\n';
    return 0;
}
