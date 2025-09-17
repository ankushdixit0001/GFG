/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

// Function to insert a node in the middle of the linked list.
class Solution {
  public:
    Node *insertInMiddle(Node *head, int x) {
        // Code Here
        Node* newNode=new Node(x);
        
        if(!head){
            return newNode;
        }
        
        Node* slow=head;
        Node* fast=head->next;
        
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        newNode->next=slow->next;
        slow->next=newNode;
    
        return head;
    }
};