/*
class Node {
	public:
	int data;
	Node *left, *right;
	
	Node(int val) {
		data = val;
		left = right = nullptr;
	}
};
*/

class Solution {
	private:
	bool isMirror(Node* n1, Node* n2) {
		if (!n1 && !n2)
			return true;
		if (!n1 || !n2)
			return false;
		return n1->data == n2->data && isMirror(n1->left, n2->right) && isMirror(n1->right, n2->left);
	}
	public:
	bool isSymmetric(Node* root) {
		// code here
		return isMirror(root->left, root->right);
		
	}
};
