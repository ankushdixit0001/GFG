/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

class Solution {
  public:
    // Function to remove duplicates from sorted linked list.
    Node* removeDuplicates(Node* head) {
        // code here
        if(!head||!head->next){
            return head;
        }
        
        Node* curr=head;
        while(curr&&curr->next){
            Node* nextNode=curr->next;
            if(curr->data==nextNode->data){
                while(nextNode&&curr->data==nextNode->data){
                    nextNode=nextNode->next;
                }
                curr->next=nextNode;
            }
            curr=nextNode;
        }
        
        return head;
    }
};