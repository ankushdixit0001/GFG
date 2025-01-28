//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void solve(int i,int n,string &s,string &permu ,unordered_set<string> &st){
        if(permu.size()==n){
            st.insert(permu);
            return;
        }
        
        for(int j=i;j<n;j++){
            swap(s[i],s[j]);
            permu.push_back(s[i]);
            solve(i+1,n,s,permu,st);
            permu.pop_back();
            swap(s[i],s[j]);
        }
    }
    vector<string> findPermutation(string &s) {
        // Code here there
        unordered_set<string>st;
        string permu;
        int n=s.size();
        solve(0,n,s,permu,st);
        vector<string> result(st.begin() , st.end());
        return result;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends