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
    Node* mergeList(Node* temp1, Node* temp2){
        //Creating dummy Node
        Node* dummyNode=new Node(-1);
        Node* res=dummyNode;
        
        while(temp1&&temp2){
            if(temp1->data<temp2->data){
                res->bottom=temp1;
                temp1=temp1->bottom;
            } else{
                res->bottom=temp2;
                temp2=temp2->bottom;
            }
            res=res->bottom;
            res->next=nullptr;
        }
        
        //remainning list
        res->bottom=temp1?temp1:temp2;
        
        return dummyNode->bottom;
    }
    Node *flatten(Node *root) {
        // code here
        if(!root||!root->next){
            return root;
        }
        
        Node* mergeRoot=flatten(root->next);
        
        return mergeList(root,mergeRoot);
        
    }
};