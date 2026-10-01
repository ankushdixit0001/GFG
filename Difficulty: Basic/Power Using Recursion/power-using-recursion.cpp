class Solution {
	public:
	int helper(int n, int p, int power) {
		if (p == 0)return power;
		power *= n;
		return helper(n, --p, power);
	}
	int recursivePower(int n, int p) {
		// code here
		return helper(n, p, 1);
	}
};
