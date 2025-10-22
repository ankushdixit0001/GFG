class Solution {
  private:
    bool isPossible(const vector<int>& arr, int k, int maxPages) {
        int students = 1, sum = 0;
        for (int pages : arr) {
            if (pages > maxPages) return false;
            if (sum + pages > maxPages) {
                students++;
                sum = pages;
            } else {
                sum += pages;
            }
        }
        return students <= k;
    }
    
  public:
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if (n < k) return -1; // Not enough books

        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        int result = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(arr, k, mid)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return result;
    }
};