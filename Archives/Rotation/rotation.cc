
#include <iostream>

// Rotate by RB
int *_rotate(int *arr, int RB, int size)
{
    for (int i = 0; i < RB; ++i)
    {
        int temp = arr[0];
        for (int x = 0; x < size - 1; x++)
        {
            arr[x] = arr[x + 1];
        }
        arr[size - 1] = temp;
    }

    return arr;
}

int main()
{
    int RB = 3;
    int arr[] = {3, 2, 1, 5, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
 
    /************ function call **************/
    int *newArr = _rotate(arr, RB, size);
    for (int j = 0; j <= size - 1; j++)
        std::cout << *(newArr + j) << " ";

    return 0;
}

