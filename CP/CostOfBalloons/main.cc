//TODO: check difficulty of the problem

#include <bits/stdc++.h>

int solve(int co_green, int co_purple, int n, 
std::vector<std::pair<bool, bool>> temp) {

    int total_cost = 0;
    for (int i = 0; i < n; i++) {
        if ((temp[i].first == 1) && temp[i].second == 1) total_cost += co_green + co_purple;
        if ((temp[i].first == 0) && temp[i].second == 1) total_cost += co_purple;
        if ((temp[i].first == 1) && temp[i].second == 0) total_cost += co_green;
    }

    return total_cost;
}

int main(void) {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int cases = 0; 
    std::cin >> cases;
    bool switchCost = true;

    while (cases--) {
        int n = 0, co_green, co_purple;
        switch (switchCost) {
            case true: {
                std::cin >> co_green >> co_purple; 
                switchCost = !switchCost;
                break;
            }
            case false: {
                std::cin >> co_purple >> co_green;
                switchCost = !switchCost;
                break;
            }
        }    
        std::cin >> n;
        std::vector<std::pair<bool, bool>> temp;

        for (int x = 0; x < n; x++) {
            int v1, v2;
            std::cin >> v1 >> v2;
            temp.push_back({v1, v2});
        }

        int min_cost = solve(co_green, co_purple, n, temp);
        std::cout << min_cost << "\n";    
    } 

    return 0;
}
