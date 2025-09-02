/* class Node { 
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
    
    Node* merge(Node* leftHead,Node* rightHead){ 
        Node* dummyNode=new Node(-1); 
        Node* temp=dummyNode;
        while(leftHead&&rightHead){
            if(leftHead->data<rightHead->data){
                temp->next=leftHead;
                leftHead=leftHead->next;
            } else {
                temp->next=rightHead;
                rightHead=rightHead->next;
            }
            temp=temp->next;
        }
        temp->next=leftHead?leftHead:rightHead;
    
        Node* result = dummyNode->next;
        delete dummyNode;
        return result;
    }
    
    Node* mergeSortHelper(Node* head) {
        // code here
        if(!head||!head->next){
            return head;
        }
    
        Node* middle=findMiddle(head);
        Node* left=head;
        Node* right=middle->next;
        middle->next=NULL;
    
        left=mergeSortHelper(left);
        right=mergeSortHelper(right);
    
        return merge(left,right);
    
    }
    
    Node* mergeSort(Node* head) {
        // code here
        if(!head||!head->next){
            return head;
        }
    
        return mergeSortHelper(head);
    
    }

};
