#include <cstring>
#include <iostream>

void solve(std::string z) {
    int len = z.length();
    char arr[len + 1];
    int zCount = 0, oCount = 0;
    std::strcpy(arr, z.c_str());

    for (int i = 0; i < len; i++) {
        switch (arr[i]) {
            case 'z':
                zCount++;
                break;
            case 'o':
                oCount++;
                break;
        }
    }

    (zCount * 2 == oCount) ? std::cout << "Yes\n" : std::cout << "No\n";
}

int main(void) {
    std::string s;
    std::cin >> s;
    solve(s);
    return 0;
}