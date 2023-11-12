#include <bits/stdc++.h>

#define lint long long int
#define testItr(a, b) for (int a = 0; a < b; a++)
#define dbg(var) std::cout << (#var) << ": " << var << '\n'
#define getType(var, nline) std::cout << typeid(var).name() << nline;

int findProduct(unsigned long int *arr, unsigned int size) {
    unsigned long long int answer = 1;
    lint constNum = 1000000000;
    for (int x = 0; x < size; x++)
        answer = answer * (*(arr + x) % (constNum + 7));
    return answer;
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int size = 0;
    std::cin >> size;
    unsigned long int elements[size] = {};
    for (int i = 0; i < size; i++) {
        std::cin >> elements[i];
    }

    std::cout << findProduct(elements, size);

    return 0;
}
