#include <iostream>

int solve(int pageLen, int pageRange) {
    bool verifyLength = false;
    bool verifyRange = false;
    if (pageLen <= 23) verifyLength = true;
    if ((pageRange > 500) && (pageRange < 1000)) verifyRange = true;

    (verifyLength && verifyRange) ? std::cout << "Take Medicine\n" : std::cout << "Don't take Medicine\n";
}

int main(void) {
    int pl, pr;  // Page length and page range
    std::cin >> pl >> pr;

    solve(pl, pr);
    return 0;
}
