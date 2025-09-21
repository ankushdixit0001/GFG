class Solution {
  public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        heights.push_back(0); // Sentinel to flush stack
        int maxArea = 0;
        for (int i = 0; i < heights.size(); ++i) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();
                int w = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, h * w);
            }
            st.push(i);
        }
        heights.pop_back(); // Restore original
        return maxArea;
    }

    int maxArea(vector<vector<int>> &mat) {
        if (mat.empty() || mat[0].empty()) return 0;
        int rows = mat.size(), cols = mat[0].size();
        vector<int> heights(cols, 0);
        int maxRect = 0;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                heights[j] = mat[i][j] == 0 ? 0 : heights[j] + 1;
            }
            maxRect = max(maxRect, largestRectangleArea(heights));
        }

        return maxRect;
    }
};
