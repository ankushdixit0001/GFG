/*structure of the node of the DLL is as
struct Node {
    int data;
    struct Node* prev, *next;
};
*/
// function should insert a new node in sorted way in
// a sorted doubly linked list
// Return the head after insertion
class Solution {
  public:
    Node* sortedInsert(Node* head, int x) {
        // Code here
        Node* newNode=new Node();
        newNode->data=x;
        newNode->next=NULL;
        newNode->prev=NULL;
        
        //insert before head
        if(!head||x<head->data){
            newNode->next=head;
            if(head){
                head->prev=newNode;
            }
            return newNode;
        }
        
        Node* temp=head;
        
        //finding insertion point
        while(temp->next&&x>temp->next->data){
            temp=temp->next;
        }
        
        //insert after temp
        newNode->next=temp->next;
        if(temp->next){
            temp->next->prev=newNode;
        }
        temp->next=newNode;
        newNode->prev=temp;
        
        return head;
    }
};