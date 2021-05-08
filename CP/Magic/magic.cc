

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

// alternate, complex, lengthy method
// #include <iostream>
// #include <vector>

// int magicFunction(int n) {
//     int elem = n;
//     long long int num, sum = 0, pos = 0;
//     int min = 1;
//     std::vector<long long int> nArray;

//     while (n--) {
//         std::cin >> num;
//         nArray.push_back(num);
//     }

//     std::vector<long long int> snArr;  // stores numbers divisible by 7
//     for (auto z : nArray) {
//         if (z % 7 == 0) snArr.push_back(z);
//     }
//     int sn = snArr[0];  // smallest number array
//     for (auto j : snArr) {
//         if (j < sn) sn = j;
//     }
//     // calcualtes smallest number's index
//     int snIndex = 0;
//     for (int b = 0; b < elem; b++) {
//         if (nArray[b] == sn) {
//             snIndex = b;
//         }
//     }

//     for (auto x : nArray) {
//         if (x == sn) continue;
//         sum += x;  // calcualtes sum
//     }

//     return -1 ? sum % 7 == 0 : snIndex;
// }

// int main(void) {
//     int n;
//     std::cin >> n;
//     int sol = magicFunction(n);
//     std::cout << sol << '\n';
//     return 0;
// }
