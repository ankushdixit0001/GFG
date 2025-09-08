/*
class Node {
public:
    int data;
    Node* next;

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
};