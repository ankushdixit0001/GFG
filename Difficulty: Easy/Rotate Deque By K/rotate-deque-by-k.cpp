class Solution {
  public:
    
    void rotateDeque(deque<int>& dq, int type, int k) {
        // code here
        int n=dq.size();
        if(n==0) return;
        
        k=k%n;
        if(type==2){
            k=n-k;
        }
        
        reverse(dq.begin(),dq.end()-k);
        reverse(dq.end()-k,dq.end());
        reverse(dq.begin(),dq.end());
        
    }
};