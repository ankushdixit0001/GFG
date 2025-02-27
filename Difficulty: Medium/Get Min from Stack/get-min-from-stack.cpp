//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int mini;
    stack<int>st;
    Solution() {
        // Code here
    }
    void push(int x) {
        if(st.empty()) mini=x;
        else if(x<=mini){
            st.push(mini);
            mini=x;
        }
        st.push(x);
    }
    void pop() {
        if(st.empty()) return;
        int temp=st.top();
        st.pop();
        if(temp==mini && !st.empty() ){
            mini=st.top();
            st.pop();
        }
    }
    int peek() {
        if(st.empty()) return -1;
        return st.top();
    }
    int getMin() {
        if(st.empty()) return -1;
        return mini;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;

        Solution ob;

        while (q--) {
            int qt;
            cin >> qt;

            if (qt == 1) {
                // push
                int att;
                cin >> att;
                ob.push(att);
            } else if (qt == 2) {
                // pop
                ob.pop();
            } else if (qt == 3) {
                // peek
                cout << ob.peek() << " ";
            } else if (qt == 4) {
                // getMin
                cout << ob.getMin() << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends