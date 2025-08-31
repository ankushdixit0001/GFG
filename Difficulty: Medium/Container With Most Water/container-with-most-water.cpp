class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n=arr.size();
        int left=0, right=n-1, ans=0, Area=0;
        
        //Time Complexity: O(n) — each element is visited at most once.
        //Space Complexity: O(1) — constant extra space
        
        while (left < right) {
            int height = min(arr[left], arr[right]);
            int breadth = right - left;
            Area = height * breadth;
            ans = max(ans, Area);
        
            // Move the pointer pointing to the shorter line
            if (arr[left] < arr[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return ans;
    }
};