class Solution {
  public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        // Sort both cost arrays in descending order
        sort(x.begin(), x.end(), greater<int>());
        sort(y.begin(), y.end(), greater<int>());

        int h_segments = 1, v_segments = 1;
        int i = 0, j = 0;
        int cost = 0;

        // Greedy selection of cuts
        while (i < x.size() && j < y.size()) {
            if (x[i] >= y[j]) {
                cost += x[i] * h_segments;
                v_segments++;
                i++;
            } else {
                cost += y[j] * v_segments;
                h_segments++;
                j++;
            }
        }

        // Remaining vertical cuts
        while (i < x.size()) {
            cost += x[i] * h_segments;
            i++;
        }

        // Remaining horizontal cuts
        while (j < y.size()) {
            cost += y[j] * v_segments;
            j++;
        }

        return cost;
    }
};