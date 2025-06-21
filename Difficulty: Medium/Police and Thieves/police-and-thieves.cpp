class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        // Code here
        int police=0;
        int thief=0;
        int ans=0;
        int n=arr.size();
        
        while(police<n&&thief<n){
            if(arr[police]=='P'&&arr[thief]=='T'){
                if(abs(police-thief)<=k){
                    ans++;
                    thief++;
                    police++;
                } else {
                    if(police<thief) police++;
                    if(thief<police) thief++;
                }
            } else {
                while(police<n&&arr[police]!='P') police++;
                while(thief<n&&arr[thief]!='T') thief++;
            }
        }
        
        return ans;
    }
};