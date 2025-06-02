class Solution {
  public:
    int peakElement(vector<int> &arr) {
        // Your code here
        int maxIdx=0;
        for(int i=1;i<arr.size();i++){
            if(arr[maxIdx]<arr[i]){
                maxIdx=i;
            }
        }
        return maxIdx;
    }
};