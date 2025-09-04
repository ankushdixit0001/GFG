/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        // code here
        //base case
        if(head==NULL){
            return NULL;
        }
        
        //reverse first k nodes
        Node* prev=NULL;
        Node* next=NULL;
        Node* curr=head;
        int count=0;
        
        while(curr!=NULL&&count<k){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
        }
        
        //recursive call 
        if(next!=NULL){
            head->next=reverseKGroup(next,k);
        }
        
        return prev;
    }
};