#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxHappiness(vector<int> &arr) {
        // Your code goes here.
        int maxh=INT_MIN;
        for(int i=0;i<arr.size()-1;i++){
            maxh=max(maxh,arr[i]+arr[i+1]);
        }
        return maxh;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);

        Solution ob;
        cout << ob.maxHappiness(arr) << endl;
        cout << "~" << endl;
    }
}
