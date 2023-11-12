//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int nextHappy(int N) {
        // code here
        while (N != 0) {
            int digit = N % 10;
            N /= 10;
            std::cout << digit << " ";
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    }
    return 0;
}
// } Driver Code Ends