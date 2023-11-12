#include <cctype>
#include <iostream>
#include <string.h>
#include <typeinfo>

#define lint long long int
#define itr(a, b) for (int a = 0; a < b; a++)
#define dbg(var) std::cout << (#var) << ": " << var << '\n'
#define getType(var, nline) std::cout << typeid(var).name() << nline;

std::string toggleString(std::string &str, int size) {
    std::string::iterator itr;
    std::string newStr;
    for (itr = str.begin(); itr != str.end(); itr++) {
        if (isupper(*itr))
            newStr += char(tolower(*itr));
        else
            newStr += char(toupper(*itr));
    }
    return newStr;
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::string inpStr;
    std::cin >> inpStr;
    std::cout << toggleString(inpStr, inpStr.size()) << " ";

    return 0;
}
