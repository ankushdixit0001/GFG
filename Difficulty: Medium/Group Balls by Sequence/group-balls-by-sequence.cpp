class Solution {
  public:
    bool validgroup(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        
        if(n%k!=0) return false;
        
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        
        sort(arr.begin(),arr.end());
        
        for(int i=0;i<n;i++){
            if(mp[arr[i]]==0) continue;
            for(int j=0;j<k;j++){
                if(mp[arr[i]+j]==0) return false;
                mp[arr[i]+j]--;
            }
        }
        
        return true;
    }
};