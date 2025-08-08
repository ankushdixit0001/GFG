/* Link list Node
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

/* Should return true if linked list is circular, else false */
class Solution {
  public:
    bool isCircular(Node *head) {
        // Your code here
        if(!head){
            return true;
        }
        Node* temp=head->next;
        while(temp!=nullptr&&temp!=head){
            temp=temp->next;
        }
        return temp==head;
    }
};