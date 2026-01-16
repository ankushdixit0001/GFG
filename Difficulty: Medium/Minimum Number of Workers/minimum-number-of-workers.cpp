class Solution {
public:
    int minMen(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int,int>> intervals;
        
        // Step 1: Build intervals
        for(int i = 0; i < n; i++) {
            if(arr[i] != -1) {
                int start = max(0, i - arr[i]);
                int end   = min(n - 1, i + arr[i]);
                intervals.push_back({start, end});
            }
        }
        
        // Step 2: Sort intervals by start
        sort(intervals.begin(), intervals.end());
        
        // Step 3: Greedy covering
        int workers = 0;
        int idx = 0;
        int currentEnd = 0;
        int farthest = 0;
        
        while(currentEnd < n) {
            bool found = false;
            // Find the interval that starts <= currentEnd and extends farthest
            while(idx < intervals.size() && intervals[idx].first <= currentEnd) {
                farthest = max(farthest, intervals[idx].second);
                idx++;
                found = true;
            }
            
            if(!found) return -1; // No interval can extend coverage
            
            workers++;
            currentEnd = farthest + 1; // Move coverage forward
        }
        
        return workers;
    }
};