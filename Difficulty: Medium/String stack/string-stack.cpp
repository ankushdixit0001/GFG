class Solution {
  public:
    bool stringStack(string &pat, string &tar) {
        int i = pat.size() - 1;
        int j = tar.size() - 1;

        while (i >= 0&&j>=0) {
            if (j >= 0 && pat[i] == tar[j]) {
                j--;
                i--;
            } else {
                i-=2;
            }
            if(j<=-1){
                return true;
            }
        }

        return false;
    }
};