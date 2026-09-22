class Solution {
	public:
	vector<int> findUnion(vector<int>& a, vector<int>& b) {
		// code here
		vector<int> ans;
		unordered_set<int> s;
		
		int n = a.size(), m = b.size();
		
		for (int i = 0; i<n || i<m; i++) {
			if (i<n && !s.count(a[i])) {
				ans.push_back(a[i]);
				s.insert(a[i]);
			}
			if (i<m && !s.count(b[i])) {
				ans.push_back(b[i]);
				s.insert(b[i]);
			}
			
		}
		return ans;
	}
};
