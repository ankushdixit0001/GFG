/* Structure of Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

class Solution {
  public:
    // Function to delete a node at given position.
    Node* deleteNode(Node* head, int x) {
        // Your code here
        if(x==1){
            Node* temp=head;
            head=head->next;
            head->prev=nullptr;
            delete temp;
            return head;
        }
        Node* temp=head;
        for(int i=1;i<x&&temp;i++){
            temp=temp->next;
        }
        if(temp){
            if(temp->prev) temp->prev->next=temp->next;
            if(temp->next) temp->next->prev=temp->prev;
            delete temp;
        }
        return head;
    }
};