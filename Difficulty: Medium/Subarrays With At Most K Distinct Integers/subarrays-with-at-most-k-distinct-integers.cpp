class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        // code here
        int count=0;
        int j=0;
        unordered_map<int,int> mp;
        
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
            
            while(mp.size()>k){
                mp[arr[j]]--;
                if(mp[arr[j]]==0){
                    mp.erase(arr[j]);
                }
                j++;
            }
            count+=(i-j+1);
        }
        return count;
    }
};