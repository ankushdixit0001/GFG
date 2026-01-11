class Solution {
public:
    string minWindow(string& s1, string& s2) {
        int n = s1.size(), m = s2.size();
        int minLen = INT_MAX;
        int start = -1;

        for (int i = 0; i < n; i++) {
            if (s1[i] == s2[0]) {
                int j = 0, k = i;
                // Forward scan to find subsequence
                while (k < n && j < m) {
                    if (s1[k] == s2[j]) j++;
                    k++;
                }
                if (j == m) { // subsequence found
                    // Backward scan to minimize window
                    int end = k - 1;
                    j = m - 1;
                    while (end >= i) {
                        if (s1[end] == s2[j]) {
                            j--;
                            if (j < 0) break;
                        }
                        end--;
                    }
                    int windowLen = k - end;
                    if (windowLen < minLen) {
                        minLen = windowLen;
                        start = end;
                    }
                }
            }
        }
        return (start == -1) ? "" : s1.substr(start, minLen);
    }
};