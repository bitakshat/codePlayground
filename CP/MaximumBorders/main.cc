#include <bits/stdc++.h>

#define lint long long int
#define itr(a, b) for (int a = 0; a < b; a++)
#define dbg(var) std::cout << (#var) << ": " << var << '\n'
#define out(var) std::cout << (#var);

using std::cout;
using std::cin;

int count_borders(std::string &str) {
    int borders = 0;
    for (int j = 0; j < str.size(); j++) {
        if (str[j] == '#') {
            borders += 1;
        }
    }

    return borders;
}
int solve(std::string str[], int n, int m) {
    int max_borders = 0, borders = 0;

    for (int i = 0; i < n; i++) {
        std::string s = str[i];
        int temp_border = count_borders(str[i]);           
        if (temp_border > max_borders) max_borders = temp_border;
    }
    return max_borders;
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t = 0;
    std::cin >> t;

    while (t-->0) {
        int n, m;
        std::cin >> n >> m;
    
        std::string temp = " ";
        std::string input[n] = {};

        for (int i = 0; i < n; i++) {
            std::cin >> temp;
            input[i] = temp;
        }

        int maximum_borders = solve(input, n, m);
        cout << maximum_borders << '\n';
    }
   
    return 0;
}