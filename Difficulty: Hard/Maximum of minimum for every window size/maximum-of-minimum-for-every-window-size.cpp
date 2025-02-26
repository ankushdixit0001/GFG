//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:
    vector<int> maxOfMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> s;
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && arr[s.top()] >= arr[i])
                s.pop();
            left[i] = (s.empty()) ? -1 : s.top();
            s.push(i);
        }
        while (!s.empty())
            s.pop();

 
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && arr[s.top()] >= arr[i])
                s.pop();
            right[i] = (s.empty()) ? n : s.top();
            s.push(i);
        }

        vector<int> result(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            int length = right[i] - left[i] - 1;
            result[length] = max(result[length], arr[i]);
        }

        for (int i = n - 1; i >= 1; --i) {
            result[i] = max(result[i], result[i + 1]);
        }

      
        result.erase(result.begin());

        return result;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        vector<int> res = ob.maxOfMins(arr);
        for (int i : res)
            cout << i << " ";
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends