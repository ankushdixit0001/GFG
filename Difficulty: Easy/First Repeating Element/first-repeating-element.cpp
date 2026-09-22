class Solution {
  public:
    int firstRepeated(vector<int> &arr) {
        // code here
        unordered_map<int,int> mp;
        
        for(int num:arr){
            mp[num]++;
        }
        
        for(int i=0;i<arr.size();i++){
            if(mp[arr[i]]>1){
                return i+1;
            }
        }
        return -1;
    }
};