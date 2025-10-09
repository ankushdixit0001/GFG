/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void postOrder(Node* root,vector<int> &nodes){
        if(!root) return;
        
        postOrder(root->left,nodes);
        postOrder(root->right,nodes);
        
        nodes.push_back(root->data);
    }
    vector<int> postOrder(Node* root) {
        // code here
        vector<int> nodes;
        postOrder(root, nodes);
        return nodes;
    }
};