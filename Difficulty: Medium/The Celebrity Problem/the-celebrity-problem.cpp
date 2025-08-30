class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        stack<int> s;
        for(int i=0;i<mat.size();i++){
            s.push(i);
        }
        while(s.size()>1){
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            
            if(mat[a][b]){
                s.push(b);
            } else {
                s.push(a);
            }
        }
        int celeb=s.top();
        
        for(int i=0;i<mat.size();i++){
            if((i!=celeb)&&(mat[celeb][i]==1||mat[i][celeb]==0)){
                return -1;
            }
        }
        return celeb;
    }
};