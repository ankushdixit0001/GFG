class Solution {
  public:
    int kBitFlips(vector<int>& nums, int k) {
        // code here
        int n = nums.size();
        int flips = 0;
        int flipCountFromPastfori = 0;
        vector<bool> isFlipped(n, false);
        for (int i = 0; i < n; i++) {
            if (i >= k && isFlipped[i - k] == true) {
                flipCountFromPastfori--;
            }
            if (flipCountFromPastfori % 2 == nums[i]) { // flip at idex i
                if (i + k > n)
                    return -1;
                flipCountFromPastfori++;
                flips++;
                isFlipped[i] = true;
            }
        }
        return flips;
    }
};