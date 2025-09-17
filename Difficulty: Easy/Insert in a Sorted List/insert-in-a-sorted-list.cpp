/*
structure of the node of the list is as
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    // Should return head of the modified linked list
    Node* sortedInsert(Node* head, int key) {
        // Code here
        Node* newNode=new Node(key);
        
        //at beginning or empty list
        if(!head||key<=head->data){
            newNode->next=head;
            return newNode;
        }
        
        //finding insertion point
        Node* curr=head;
        while(curr->next&&curr->next->data<key){
            curr=curr->next;
        }
        
        //insert after curr
        newNode->next=curr->next;
        curr->next=newNode;
        
        return head;
    }
};