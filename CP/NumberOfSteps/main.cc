#include <iostream>
#include <climits>

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    int FA[n] = {}, SA[n] = {};

    for (int i = 0; i < n; i++) {
        int inp;
        std::cin >> inp;
        FA[i] = inp;
    }

    for (int i = 0; i < n; i++) {
        int inp;
        std::cin >> inp;
        SA[i] = inp;
    }

    int min = INT_MAX, count = 0;
    for (int i = 0; i < n; i++) {
       if(FA[i] < min) {
           min = FA[i];
       }
    }

    for (int i = 0; i < n; i++) {
        while(FA[i] > min) {
            FA[i] = FA[i] - SA[i];
            count += 1;
            if(FA[i] == min) {
                continue;
            }
        }
        if (FA[i] < min) {
            min = FA[i];
            i = -1;
        }
        if (min < 0) {
            count = -1;
            break;
        }
    }  
    

    std::cout << count << '\n';
    return 0;
}


// std::ios_base::sync_with_stdio(false);
//     std::cin.tie(NULL);
    
//     int n = 5;
//     printf("Enter n: ");
//     std::cin >> n;
//     // unsigned int FA[n] = {};
//     // unsigned int VB[n] = {};
//     std::vector<int> VA, VB;

//     auto input = []() -> int {
//         static int num;
//         std::cin >> num;
//   		return num;
// 	};
//     static int current = 0;
// 	std::generate(std::begin(VA), std::end(VA), input);
// 	std::generate(std::begin(VB), std::end(VB), input);

//     // int ans = NOS(n, VA, VB);
//     std::cout << INT_MAX << '\n';