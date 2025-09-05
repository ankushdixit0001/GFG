/*
struct Node
{
    int data;
    struct Node *next;

    Node(int x){
        data =x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* reverse(Node* head){
        Node* prev=nullptr;
        Node* next=nullptr;
        Node* curr=head;
        
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        
        return prev;
    }
    Node* merge(Node* head1, Node* head2){
        if(!head1) return head2;
        if(!head2) return head1;
        
        Node* dummyNode= new Node(-1);
        Node* tail=dummyNode;
        
        while(head1&&head2){
            if(head1->data<head2->data){
                tail->next=head1;
                head1=head1->next;
            } else {
                tail->next=head2;
                head2=head2->next;
            } 
            tail=tail->next;
        }
        
        tail->next=head1?head1:head2;
        
        Node* newHead=dummyNode->next;
        delete dummyNode;
        
        return newHead;
    }
    
    Node* sort(Node* head) {
        // Code here
        if(!head||!head->next){
            return head;
        }
        
        Node* AHead= new Node(-1);
        Node* DHead= new Node(-1);
        
        Node* asc=AHead;
        Node* des=DHead;
        
        Node* curr=head;
        while(curr){
            asc->next=curr;
            asc=asc->next;
            curr=curr->next;
            
            if(curr){
                des->next=curr;
                des=des->next;
                curr=curr->next;
            }
        }
        
        asc->next=nullptr;
        des->next=nullptr;
        
        Node* ANode=AHead->next;
        
        //reverse
        Node* DNode=reverse(DHead->next);
        
        delete AHead;
        delete DHead;
        
        //merge
        return merge(ANode,DNode);
    }
};