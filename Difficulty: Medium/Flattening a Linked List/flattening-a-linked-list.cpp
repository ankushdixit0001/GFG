/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
  public:
    Node* merge(Node* temp1,Node* temp2){
        Node* dummy=new Node(-1);
        Node* res=dummy;
        
        while(temp1&&temp2){
            if(temp1->data<temp2->data){
                res->bottom=temp1;
                res=temp1;
                temp1=temp1->bottom;
            } else {
                res->bottom=temp2;
                res=temp2;
                temp2=temp2->bottom;
            }
            res->next=NULL;
        }
        //attach remaining nodes
        res->bottom = temp1 ? temp1 : temp2;
        
        return dummy->bottom;
    }
    
    Node* helper(Node* head){
        if(!head||!head->next){
            return head;
        }
        
        Node* mergeHead=helper(head->next);
        
        return merge(head,mergeHead);
    }
    
    Node *flatten(Node *root) {
        // Your code here
        if(!root||!root->next){
            return root;
        }
        
        return helper(root);
    }
};