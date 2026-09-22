class Solution {
  public:
    vector<int> frequencyCount(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int>ans(n,0);
        
        for(int num:arr){
            if(num>=1&&num<=n){
                ans[num-1]+=1;
            }
            
        }
        return ans;
    }
};
