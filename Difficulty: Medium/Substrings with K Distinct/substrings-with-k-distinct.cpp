class Solution {
public:
    int atMostK(const string& s, int k) {
        int freq[26] = {0};
        int distinct = 0;
        int left = 0, result = 0;

        for (int right = 0; right < (int)s.size(); right++) {
            if (freq[s[right] - 'a'] == 0) distinct++;
            freq[s[right] - 'a']++;

            while (distinct > k) {
                freq[s[left] - 'a']--;
                if (freq[s[left] - 'a'] == 0) distinct--;
                left++;
            }

            result += (right - left + 1);
        }
        return result;
    }

    int countSubstr(string& s, int k) {
        return atMostK(s, k) - atMostK(s, k - 1);
    }
};