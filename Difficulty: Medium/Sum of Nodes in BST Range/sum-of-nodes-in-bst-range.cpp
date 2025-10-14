/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    int nodeSum(Node* root, int l, int r) {
        // code here
        if(!root){
            return 0;
        }
        
        int left=nodeSum(root->left,l,r);
        int right=nodeSum(root->right,l,r);
        
        int data=(root->data>=l&&root->data<=r)?root->data:0;
        
        return left+right+data;
    }
};
