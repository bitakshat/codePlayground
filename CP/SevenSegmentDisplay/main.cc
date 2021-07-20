#include <iostream>

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while(t--) {
        int testNum;
        std::cin >> testNum;
                            /*0, 1, 2, 3, 4, 5, 6, 7, 8, 9*/
        int segmentCount[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
        int stickCount = 0;

        if(testNum == 0) {
            stickCount = segmentCount[0];
        } else {
            while(testNum != 0) {
                int digit = testNum % 10;
                testNum /= 10;
                stickCount += segmentCount[digit];
            }
        }
        
        while(stickCount != 0) {
            if(stickCount % 2 == 0) {
                std::cout << "1";
                stickCount -= 2;
            } else {
                stickCount -= 3;
                std::cout << "7";
            }
        }
        std::cout << '\n';
    }
    return 0;
}