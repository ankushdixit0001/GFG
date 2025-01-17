//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        //1st method 
        
        // vector<int> res;
        // int pro=1;
        // for(int i=0;i<arr.size();i++){
        //     pro=pro*arr[i];
        // }
        // for(int i=0;i<arr.size();i++){
        //     res.push_back(pro/arr[i]);
        // }
        // return res;
         
        // 2nd method
        
        int n=arr.size();
        vector<int> res(n,1);
        
        int leftPro=1;
        for(int i=0;i<n;i++){
            res[i]=leftPro;
            leftPro*=arr[i];
        }
        
        int rightPro=1;
        for(int i=n-1;i>=0;i--){
            res[i]*=rightPro;
            rightPro*=arr[i];
        }
        return res;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        Solution obj;
        vector<int> res = obj.productExceptSelf(arr);

        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends