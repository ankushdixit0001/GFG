/*
class Node {
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
    vector<int> zigZagTraversal(Node* root) {
        // code here
        vector<int> res;
        if(!root) return res;
        
        queue<Node*> q;
        q.push(root);
        bool flag=true;
        
        while(!q.empty()){
            int size=q.size();
            vector<int> ans(size);
            
            for(int i=0;i<size;i++){
                Node* frontNode=q.front();
                q.pop();
                
                int index=flag?i:size-i-1;
                ans[index]=frontNode->data;
                
                if(frontNode->left) q.push(frontNode->left);
                if(frontNode->right) q.push(frontNode->right);
            }
            
            flag=!flag;
            for(int val:ans) res.push_back(val);
        }
        
        return res;
    }
};