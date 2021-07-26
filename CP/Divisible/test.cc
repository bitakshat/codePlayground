#include <iostream>

int main()
{
    int size = 5;
    int arr[size];
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    for (int x = 0; x < size; x++) {
        std::cout << arr[x] << " ";
    }
    return 0;
}
