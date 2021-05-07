#include <iostream>
#include <vector>

int magicFunction(int n) {
    int num, sum = 0;
    std::vector<int> nArray;

    // for (int i = 0; i < n; i++) {
    //     std::cin >> num;
    //     nArray.push_back(num);
    // }

    while (n--) {
        std::cin >> num;
        nArray.push_back(num);
    }
    // sum
    for (auto z : nArray) {
        sum += z;
    }
    std::cout << "Sum: " << sum << '\n';
    return 0;
}

int main(void) {
    int n;
    std::cin >> n;

    int sol = magicFunction(n);
    return 0;
}