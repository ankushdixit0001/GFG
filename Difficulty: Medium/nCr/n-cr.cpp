//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    long long factorial(int num) {
        long long fact = 1;
        for (int i = 1; i <= num; i++) {
            fact *= i;
        }
        return fact;
    }


  public:
    int nCr(int n, int r) {
        // code here
        if (r > n) return 0;  // Invalid case
        if (r == 0 || r == n) return 1;  // Base cases

        long long result = 1;
        r = std::min(r, n - r);  // Optimization: compute the smaller side

        for (int i = 0; i < r; i++) {
            result = result * (n - i) / (i + 1);  // Avoid full factorial computation
        }

        return result;


    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, r;
        cin >> n >> r;

        Solution ob;
        cout << ob.nCr(n, r) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends