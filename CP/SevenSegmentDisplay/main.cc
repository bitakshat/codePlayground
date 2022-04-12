#include <bits/stdc++.h>

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int t;
    std::cin >> t;
    // std::string testNum =
    //     "8445914752334217384616425239834258842968210917150466215005566541456111"
    //     "472213037091760933758638073416";
    std::string testNum;
    std::cin >> testNum;
                        /*0, 1, 2, 3, 4, 5, 6, 7, 8, 9*/
    int segmentCount[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    unsigned long int stickCount = 0;

    if (testNum == 0) {
        stickCount = segmentCount[0];
    } else {
        while (testNum != 0) {
            int digit = testNum % 10;
            testNum /= 10;
            stickCount += segmentCount[digit];
        }
    }

    std::cout << '\n';

    return 0;
}