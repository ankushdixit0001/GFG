class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        // code here
        if(k>arr.size()) return -1;
        
        //Xor of first k element
        int currXor=0;
        for(int i=0;i<k;i++){
            currXor^=arr[i];
        }
        
        int res=currXor;
        
        //sliding window
        for(int i=k;i<arr.size();i++){
            currXor^=arr[i]; //add element
            currXor^=arr[i-k]; //remove element
            res=max(res,currXor);
        }
        
        return res;
    }
};