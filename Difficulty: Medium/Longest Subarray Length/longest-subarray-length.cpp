class Solution {
  public:
    int longestSubarray(vector<int>& arr) {
    int n = arr.size();
    vector<int> nextGreater(n, n);
    vector<int> prevGreater(n, -1);
    stack<int> st;

    // Next Greater Element (NGE)
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && arr[st.top()] < arr[i]) {
            nextGreater[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    while (!st.empty()) st.pop();

    // Previous Greater Element (PGE)
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && arr[st.top()] < arr[i]) {
            prevGreater[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    int maxLen = 0;
    for (int i = 0; i < n; ++i) {
        int windowLen = nextGreater[i] - prevGreater[i] - 1;
        if (arr[i] <= windowLen) {
            maxLen = max(maxLen, windowLen);
        }
    }

    return maxLen;
}

};