class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        int n = arr.size();
        int left = 0, maxLen = 0, startIdx = 0;
        multiset<int> window;

        for (int right = 0; right < n; ++right) {
            window.insert(arr[right]);

            // Shrink window if max - min > x
            while (*window.rbegin() - *window.begin() > x) {
                window.erase(window.find(arr[left]));
                ++left;
            }

            // Update longest window
            if (right - left + 1 > maxLen) {
                maxLen = right - left + 1;
                startIdx = left;
            }
        }

        return vector<int>(arr.begin() + startIdx, arr.begin() + startIdx + maxLen);
    }
};
