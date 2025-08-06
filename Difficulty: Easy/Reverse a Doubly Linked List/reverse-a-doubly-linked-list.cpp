/*
class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/
class Solution {
  public:
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) {
        // Your code here
        if(!head){
            return head;
        }
        DLLNode* temp=head;
        DLLNode* prevNode=NULL;
        while(temp){
            DLLNode* nextNode=temp->next;
            //swap
            temp->next=prevNode;
            temp->prev=nextNode;
            //update
            prevNode=temp;
            temp=nextNode;
        }
        head= prevNode;
        return head;
    }
};