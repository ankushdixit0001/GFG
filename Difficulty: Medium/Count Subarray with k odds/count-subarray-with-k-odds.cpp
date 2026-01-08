class Solution {
  public:
  int solve(vector<int> arr,int k){
      int i=0,j=0,n=arr.size(),count=0,ans=0;
      
      while(i<n){
          if(arr[i]%2==1){
              count++;
          }
          
          while(count>k){
              if(arr[j]%2==1){
                  count--;
              }
              j++;
          }
          ans+=(i-j+1);
          i++;
      }
      return ans;
  }
    int countSubarrays(vector<int>& arr, int k) {
        // code here
        return solve(arr,k)-solve(arr,k-1);
        
    }
};