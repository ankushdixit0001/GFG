class Solution {
  public:
    void backtrack(int start, int k, int n, vector<int>& path, vector<vector<int>>& res) {
        if (k == 0 && n == 0) {
            res.push_back(path);
            return;
        }
        if (k == 0 || n <= 0) return;

        for (int i = start; i <= 9; ++i) {
            path.push_back(i);
            backtrack(i + 1, k - 1, n - i, path, res);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(int n, int k) {
        vector<vector<int>> res;
        vector<int> path;
        backtrack(1, k, n, path, res);
        return res;
    }
};
