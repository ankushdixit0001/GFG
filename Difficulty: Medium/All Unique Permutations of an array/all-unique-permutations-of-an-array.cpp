class Solution {
  public:
    vector<vector<int>> uniquePerms(vector<int>& arr) {
        vector<vector<int>> result;
        vector<int> path;
        sort(arr.begin(), arr.end()); // ensures lexicographic order
        vector<bool> used(arr.size(), false);
        backtrack(arr, used, path, result);
        return result;
    }

  private:
    void backtrack(vector<int>& arr, vector<bool>& used, vector<int>& path, vector<vector<int>>& result) {
        if (path.size() == arr.size()) {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < arr.size(); ++i) {
            if (used[i]) continue;
            if (i > 0 && arr[i] == arr[i - 1] && !used[i - 1]) continue; // skip duplicates
            used[i] = true;
            path.push_back(arr[i]);
            backtrack(arr, used, path, result);
            path.pop_back();
            used[i] = false;
        }
    }
};
