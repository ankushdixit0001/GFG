/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int findMaxSumRec(Node* root, int& res) {
        if (root == NULL)
            return 0;
    
        int l = max(0, findMaxSumRec(root->left, res));
        int r = max(0, findMaxSumRec(root->right, res));
    
        res = max(res, l + r + root->data);
    
        return root->data + max(l, r);
    }
    
    int findMaxSum(Node *root) {
        // code here
        int res=root->data;
        findMaxSumRec(root,res);
        return res;
    }
};