

#include <iostream>
#include <vector>

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int size, n;
    std::cin >> size;
    std::vector<int> arr;

    for (int i = 0; i < size; i++) {
        std::cin >> n;
        arr.push_back(n);
    }

    (arr[size - 1] % 10 == 0) ? std::cout << "Yes\n" : std::cout << "No\n";
    return 0;
}

// #include <iostream>
// #include <vector>

// int main(void) {
//     std::ios_base::sync_with_stdio(false);
//     std::cin.tie(NULL);

//     int size, n;
//     std::cin >> size;
//     std::vector<int> arr;
//     std::string numStr = "";

//     for (int i = 0; i < size; i++) {
//         std::cin >> n;
//         arr.push_back(n);
//     }

//     for (auto z : arr) {
//         int LD = z % 10;  // last digit
//         numStr += std::to_string(LD);
//     }

//     (std::stoi(numStr) % 10 == 0) ? std::cout << "Yes\n" : std::cout << "No\n";
//     return 0;
// }
