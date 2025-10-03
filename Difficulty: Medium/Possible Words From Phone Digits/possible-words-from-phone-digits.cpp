class Solution {
  public:
    vector<string> possibleWords(vector<int> &arr) {
        vector<string> result;
        if (arr.empty()) return result;

        vector<string> keypad = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };

        string current;
        backtrack(arr, keypad, 0, current, result);
        return result;
    }

  private:
    void backtrack(const vector<int>& arr, const vector<string>& keypad,
                   int index, string& current, vector<string>& result) {
        if (index == arr.size()) {
            result.push_back(current);
            return;
        }

        string letters = keypad[arr[index]];
        if (letters.empty()) {
            backtrack(arr, keypad, index + 1, current, result); // skip digit but continue
            return;
        }

        for (char ch : letters) {
            current.push_back(ch);
            backtrack(arr, keypad, index + 1, current, result);
            current.pop_back(); // backtrack
        }
    }
};
