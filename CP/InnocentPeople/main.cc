#include <iostream>
#include <sstream>
#include <typeinfo>

void helpInnocent(std::string &str) {
    bool isEven = false, inVowels = false;
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};

    // type of str[x] = c
    for (int i = 0; i < 5; i++) {
        if (str[2] == vowels[i]) {
            inVowels = true;
        }
    }

    for (int x = 0; x < 9; x++) {
        if (x == 2 or x == 6) continue;

        if ((str[x] + str[x + 1]) % 2 == char(47)) {
            isEven = true;
        }
    }

    (isEven && inVowels) ? std::cout << "valid" : std::cout << "invalid";
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string iStr = "12X2345-67";
    std::string testStr = "11B242-73";   // valid test case 2
    std::string testStr1 = "13X357-22";  // valid test case 12

    helpInnocent(testStr1);
    return 0;
}
