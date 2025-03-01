//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    string decodedString(string &s) {
        // code here
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i]!=']'){
                st.push(s[i]);
            } else {
                string temp;
                while(!st.empty()&&st.top()!='['){
                    temp.push_back(st.top());
                    st.pop();
                }
                reverse(temp.begin(),temp.end());
                st.pop();
                string num;
                while(!st.empty() && isdigit(st.top())){
                    num.push_back(st.top());
                    st.pop();
                }
                reverse(num.begin(),num.end());
                int number=stoi(num);
                string repeat;
                for(int j=0;j<number;j++){
                    repeat.append(temp);
                }
                for(char c:repeat){
                    st.push(c);
                }
            }
        }
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends