#include <iostream>
#include <cstring>

int main() {
    int t;
    char VOWEL_UPPERCASE[5] = { 'A', 'E', 'I', 'O', 'U' };
    char VOWEL_LOWERCASE[5] = { 'a', 'e', 'i', 'o', 'u' };
    std::cin >> t;

    for (int i = 0; i < t; i++) {
        std::string s;
        std::cin >> s;
        int stringSize = s.length();
        char CA[stringSize];        // CHARACTER ARRAY
        int BA[stringSize] = { 0 }; // BINARY ARRAY
        std::strcpy(CA, s.c_str());

        // checks upper case wowels in chr_arr
        int size = sizeof(CA) / sizeof(CA[0]);
        for (int x = 0; x < size; x++) {
            for (int y = 0; y < 5; y++) {
                if (CA[x] == VOWEL_UPPERCASE[y] || CA[x] == VOWEL_LOWERCASE[y]) {
                    BA[y] += 1;
                }
            }
        }

        int sum = 0;
        int h = 0;
        for (int i = 0; i <= stringSize; i++) {
            if (BA[i] >= 1) {
                h += 1;
            }
        }

        h >= 5 ? std::cout << "lovely string" << std::endl : std::cout << "ugly string" << std::endl;
    }

    return 0;
}
