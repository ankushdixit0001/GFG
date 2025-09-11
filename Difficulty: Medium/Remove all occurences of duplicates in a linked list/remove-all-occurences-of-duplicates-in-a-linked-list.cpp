// User function Template for C++

/* Linked List node structure

struct Node {
    int data;
    struct Node *next;
};

*/

class Solution {
  public:
    Node* removeAllDuplicates(struct Node* head) {
        // code here
        Node* dummy=new Node(-1);
        dummy->next=head;
        
        Node* prev=dummy;
        Node* curr=head;
        
        while(curr){
            if(curr->next&&curr->data==curr->next->data){
                int dup=curr->data;
                while(curr&&curr->data==dup){
                    curr=curr->next;
                }
                prev->next=curr;
                continue;
            } else {
                prev=curr;
                curr=curr->next;
            }
        }
        
        return dummy->next;
    }
};