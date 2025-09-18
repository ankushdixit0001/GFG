class Solution {
  public:
    vector<int> nextGreater(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int> ans(n);
        stack<int> st;
        
        for (int i = 2 * n - 1; i >= 0; i--) {
            int idx = i % n;

            // Pop elements that are smaller or equal to current
            while (!st.empty() && st.top() <= arr[idx]) {
                st.pop();
            }

            // Fill answer only in first pass
            if (i < n) {
                ans[idx] = st.empty() ? -1 : st.top();
            }

            // Push current element to stack
            st.push(arr[idx]);
        }

        return ans;
    }
};