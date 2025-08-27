/*
class NodeLL {
  public:
    int 
    ;
    data;
    NodeLL *next;

    NodeLL(int x) {
        data = x;
        next = NULL;
    }
};
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    Node *linkedListToBinaryTree(NodeLL *head) {
        // base case
        if(!head) return nullptr;
        // root
        Node* root=new Node(head->data);
        queue<Node*> q;
        q.push(root);
        head=head->next;
        
        while(head){
            Node* parent=q.front();
            q.pop();
            // build left node
            if(head){
                Node* left=new Node(head->data);
                parent->left=left;
                q.push(left);
                head=head->next;
            }
            // build right node
            if(head){
                Node* right=new Node(head->data);
                parent->right=right;
                q.push(right);
                head=head->next;
            }
        }
        return root;
    }
};