class Solution {
  public:
    string caseSort(string& s) {
        // code here
        int n=s.length();
        vector<char> lower, upper;
        
        for(const auto& ch : s){
            if(islower(ch)){
                lower.push_back(ch);
            } else {
                upper.push_back(ch);
            }
        }
        
        sort(lower.begin(),lower.end());
        sort(upper.begin(),upper.end());
        
        string result(n,' ');
        int lowerIdx=0 , upperIdx=0;
        
        for(int i=0;i<n;i++){
            if(islower(s[i])){
                result[i]=lower[lowerIdx++];
            } else {
                result[i]=upper[upperIdx++];
            }
        }
        
        return result;
    }
};