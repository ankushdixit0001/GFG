/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

class Solution {
  public:
    Node* findIntersection(Node* head1, Node* head2) {
        // code goes here.
        Node* dummyNode=new Node(-1);
        Node* tail=dummyNode;
        
        while(head1&&head2){
            if(head1->data==head2->data){
                tail->next=head1;
                tail=tail->next;
                head1=head1->next;
                head2=head2->next;
            } else if(head1->data<head2->data){
                head1=head1->next;
            } else{
                head2=head2->next;
            }
        }
        tail->next=NULL;
        
        Node* head=dummyNode->next;
        delete dummyNode;
        
        return head;
    }
};