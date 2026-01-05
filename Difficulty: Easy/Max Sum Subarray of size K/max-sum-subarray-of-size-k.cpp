class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        if(k>arr.size()) return -1;//invalid case
        
        int currSum=0;
        for(int i=0;i<k;i++){
            currSum+=arr[i];
        }
        
        int maxSum=currSum;//first window sum
        
        for(int i=k;i<arr.size();i++){
            currSum+=arr[i]-arr[i-k];//slide window
            maxSum=max(maxSum,currSum);
        }
        
        return maxSum;
    }
};