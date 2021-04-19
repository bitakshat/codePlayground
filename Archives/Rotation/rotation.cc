
#include <iostream>
#include <random>

// Rotate by RB
int *rotate(int *arr, int RB, int size)
{
    for ( int i = 0; i < RB; ++i ) {
        int temp = arr[0];
        for ( int x = 0; x < size - 1; x++ ) {
            arr[x] = arr[x + 1];
        }
        arr[size - 1] = temp;
    }
    return arr;
}

int main()
{      
    std::random_device r;
    std::mt19937 mt1(r());
    std::uniform_int_distribution<int> d1(5, 10);
    int range = d1(r);

    // RB value can be changed by user
    int RB = 1;
    int arr[] = {};
    
    for( int x = 0; x < range; x++ ) {
        std::random_device v;
        std::mt19937 mt2(v());
        std::uniform_int_distribution<int> d2(0, 9);
        arr[x] = d2(mt2);
    }

    std::cout << "initial array: " << std::endl;
    for( int j = 0; j < range; j++ ) {
        std::cout << arr[j] << " ";
    }
    
    /**************** function call *****************/
    std::cout << std::endl << "array after rotation: " << std::endl;
    int *newArr = rotate(arr, RB, range);
    for (int j = 0; j <= range - 1; j++)
        std::cout << *(newArr + j) << " ";
    
    return 0;
}