/*
// structure of the node is as follows

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
    Node* findMiddle(Node* head){
        Node* slow=head;
        Node* fast=head->next;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
    Node* merge(Node* leftHead, Node* rightHead){
        if(!leftHead) return rightHead;
        if(!rightHead) return leftHead;
        
        Node* dummyNode=new Node(-1);
        Node* curr=dummyNode;
        
        while(leftHead&&rightHead){
            if(leftHead->data<rightHead->data){
                curr->next=leftHead;
                leftHead=leftHead->next;
            } else {
                curr->next=rightHead;
                rightHead=rightHead->next;
            }
            curr=curr->next;
        }
        curr->next=leftHead?leftHead:rightHead;
        
        Node* result=dummyNode->next;
        delete dummyNode;
        
        return result;
    }
    
    Node* mergeSort(Node* head) {
        // code here
        if(!head||!head->next){
            return head;
        }
        
        Node* middle=findMiddle(head);
        
        Node* left=head;
        Node* right=middle->next;
        middle->next=nullptr;
        
        left=mergeSort(left);
        right=mergeSort(right);
        
        return merge(left,right);
        
    }
    
    Node* removeDublicate(Node* head){
        Node* curr=head;
        
        while(curr&&curr->next){
            if(curr->data==curr->next->data){
                Node* nextNode=curr->next;
                
                while(nextNode&&curr->data==nextNode->data){
                    nextNode=nextNode->next;
                }
                
                curr->next=nextNode;
            } 
            curr=curr->next;
        }
        
        return head;
    }
    
    struct Node* makeUnion(struct Node* head1, struct Node* head2) {
        // code here
        head1=mergeSort(head1);
        head2=mergeSort(head2);
        
        Node* head=merge(head1,head2);
        
        return removeDublicate(head);
        
    }
};