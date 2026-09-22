class Solution {
  public:
    bool checkEqual(vector<int>& a, vector<int>& b) {
        // code here
        unordered_map<int,int> mp;
        
        int n=a.size(), m=b.size();
        if(n!=m) return false;
        
        for(int i=0;i<n;i++){
            mp[a[i]]++;
        }
        for(int i=0;i<n;i++){
            if(mp[b[i]]>0){
                mp[b[i]]--;
            } else {
                return false;
            }
        }
        return true;
    }
};