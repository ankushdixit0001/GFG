class Solution {
  public:
    void generate(int n, string &current, vector<string> &result) {
        if (current.length() == n) {
            result.push_back(current);
            return;
        }
        current.push_back('0');
        generate(n, current, result);
        current.pop_back();

        current.push_back('1');
        generate(n, current, result);
        current.pop_back();
    }

    vector<string> binstr(int n) {
        vector<string> result;
        string current;
        generate(n, current, result);
        return result;
    }
};
