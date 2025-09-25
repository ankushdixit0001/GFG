class Solution {
  public:
    string intToBinary(int num) {
        if (num == 0) return "0";
        string binary = "";
        while (num > 0) {
            binary = (num % 2 == 0 ? "0" : "1") + binary;
            num /= 2;
        }
        return binary;
    }
    
    vector<string> generateBinary(int n) {
        // code here
        vector<string> ans;
        
        for(int i=1;i<=n;i++){
            string binary=intToBinary(i);
            ans.push_back(binary);
            
        }
        
        return ans;
    }
};