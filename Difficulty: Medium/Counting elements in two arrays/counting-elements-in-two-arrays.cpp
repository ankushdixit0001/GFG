class Solution {
  public:
    int smaller(const vector<int>& arr, int key) {
        return upper_bound(arr.begin(), arr.end(), key) - arr.begin();
    }

    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        // code here
        vector<int> ans;
        sort(b.begin(),b.end());
        for(int i=0;i<a.size();i++){
            int count=smaller(b,a[i]);
            ans.push_back(count);
        }
        return ans;
    }
};