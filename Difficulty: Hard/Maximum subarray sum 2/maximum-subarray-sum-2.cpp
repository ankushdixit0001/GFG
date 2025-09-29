class Solution {
  public:
    int maxSubarrSum(vector<int>& arr, int a, int b) {
        int n = arr.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i)
            prefix[i + 1] = prefix[i] + arr[i];

        deque<int> dq;
        long long maxSum = LLONG_MIN;

        for (int i = a; i <= n; ++i) {
            // Remove indices out of window [i - b, i - a]
            while (!dq.empty() && dq.front() < i - b)
                dq.pop_front();

            // Add new candidate prefix[i - a]
            while (!dq.empty() && prefix[dq.back()] >= prefix[i - a])
                dq.pop_back();
            dq.push_back(i - a);

            // Update maxSum using current prefix[i] - min prefix in window
            maxSum = max(maxSum, prefix[i] - prefix[dq.front()]);
        }

        return static_cast<int>(maxSum);
    }
};
