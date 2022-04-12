#include <iostream>
#include <sstream>

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long int size;
    std::cin >> size;

    long long int arr[size];
    std::stringstream ss;
    // creating array
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];     }

    // iteration for first half
    for (int i = 0; i < size/2; i++) {
        
        while (arr[i] >= 10) 
            arr[i] /= 10;
            ss << arr[i];
    }

    // iteration for second half
    for (int i = size / 2; i < size; i++) {
        ss << arr[i] % 10;
    }

    int number;
    ss >> number;

    // number % 11 == 0 ? std::cout << "OUI\n" : std::cout << "NON\n";
    number % 11 == 0 ? std::cout << "OUI\n" : std::cout << "NON\n";
    return 0;
}