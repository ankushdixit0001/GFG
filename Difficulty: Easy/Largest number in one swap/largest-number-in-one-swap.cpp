class Solution {
  public:
    string largestSwap(string &s) {
        // code here
        char maxDigi='0';
        int ind=-1;
        int l=-1;
        int r=-1;
        
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]>maxDigi){
                maxDigi=s[i];
                ind=i;
            } else if(s[i]<maxDigi){
                l=i;
                r=ind;
            }
        }
        
        if(l==-1) return s;
        
        swap(s[l],s[r]);
        
        return s;
    }
};