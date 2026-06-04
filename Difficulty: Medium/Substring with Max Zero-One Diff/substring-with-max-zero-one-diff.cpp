class Solution {
public:
    int maxSubstring(string &s) {
        int ans = INT_MIN;
        int curr = 0;

        for(char c : s) {
            int val = (c == '0') ? 1 : -1;  
            curr = max(val, curr + val);   
            ans = max(ans, curr);
        }

        return ans > 0 ? ans : -1;
    }
};
