class Solution {
public:
    int sumOfModes(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> freq; // frequency of elements in current window
        int maxFreq = 0;
        unordered_map<int, set<int>> freqToValues; // maps frequency to values
        int sum = 0;

        // Step 1: Build frequency map for first window
        for (int i = 0; i < k; i++) {
            int val = arr[i];
            int oldFreq = freq[val];
            freq[val]++;
            if (oldFreq > 0) {
                freqToValues[oldFreq].erase(val);
                if (freqToValues[oldFreq].empty()) freqToValues.erase(oldFreq);
            }
            freqToValues[oldFreq + 1].insert(val);
            maxFreq = max(maxFreq, oldFreq + 1);
        }

        sum += *freqToValues[maxFreq].begin(); // add mode of first window

        // Step 2: Slide the window
        for (int i = k; i < n; i++) {
            int out = arr[i - k];
            int in = arr[i];

            // Remove outgoing element
            int oldFreqOut = freq[out];
            freqToValues[oldFreqOut].erase(out);
            if (freqToValues[oldFreqOut].empty()) freqToValues.erase(oldFreqOut);
            freq[out]--;
            if (freq[out] > 0) {
                freqToValues[oldFreqOut - 1].insert(out);
            } else {
                freq.erase(out);
            }

            // Add incoming element
            int oldFreqIn = freq[in];
            freq[in]++;
            if (oldFreqIn > 0) {
                freqToValues[oldFreqIn].erase(in);
                if (freqToValues[oldFreqIn].empty()) freqToValues.erase(oldFreqIn);
            }
            freqToValues[oldFreqIn + 1].insert(in);
            maxFreq = max(maxFreq, oldFreqIn + 1);

            // Adjust maxFreq if needed
            while (freqToValues.find(maxFreq) == freqToValues.end()) {
                maxFreq--;
            }

            sum += *freqToValues[maxFreq].begin(); // add mode of current window
        }

        return sum;
    }
};