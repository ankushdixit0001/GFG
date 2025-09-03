/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        if(!head||!head->next) return head;
        
        Node* temp=head;
        Node* prevNode=NULL;
        while(temp){
            //swap
            Node* nextNode=temp->next;
            temp->next=prevNode;
            temp->prev=nextNode;
            
            prevNode=temp;
            temp=nextNode;
        }
        return prevNode;
    }
};