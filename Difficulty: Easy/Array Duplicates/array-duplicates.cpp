class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        // code here 
        vector<int> result;
        sort(arr.begin(),arr.end());
        int prev=-1;
        for(int i=0;i<arr.size();i++){
            int curr=arr[i];
            if(curr==prev){
                result.push_back(curr);
                while(i+1<arr.size()&&arr[i+1]==prev){
                    i++;
                }
            }
            prev=curr;
        }
        return result;
    }
};