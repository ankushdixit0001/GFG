/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
};

*/
class Solution {
  public:
    Node* reverse(Node* head){
        if(!head||!head->next) return head;
        
        Node* prev=NULL;
        Node* temp=head;
        
        while(temp){
            Node* nextNode=temp->next;
            temp->next=prev;
            prev=temp;
            temp=nextNode;
        }
        return prev;
    }
    
    struct Node *mergeResult(Node *node1, Node *node2) {
        // your code goes here
        if(!node1) return reverse(node2);
        if(!node2) return reverse(node1);
        
        node1=reverse(node1);
        node2=reverse(node2);
        
        Node* dummyNode=new Node(-1);
        Node* curr=dummyNode;
        
        while(node1&&node2){
            if(node1->data>node2->data){
                curr->next=node1;
                node1=node1->next;
            } else {
                curr->next=node2;
                node2=node2->next;
            }
            curr=curr->next;
        }
        
        if(node1) curr->next=node1;
        if(node2) curr->next=node2;
        
        Node* result=dummyNode->next;
        delete dummyNode;
        
        return result;
    }
};