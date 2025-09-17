/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
}; */

class Solution {
  public:
    Node* reverse(Node* head){
        if(!head||!head->next){
            return head;
        }
        
        Node* prev=nullptr;
        Node* curr=head;
        Node* nextNode=nullptr;
        while(curr){
            nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
        return prev;
    }
    
    void reorderList(Node* head) {
        if (!head || !head->next || !head->next->next) return;
    
        // Step 1: Find the middle
        Node* slow = head;
        Node* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
    
        // Step 2: Reverse second half
        Node* second = reverse(slow->next);
        slow->next = nullptr;
    
        // Step 3: Merge two halves in-place
        Node* first = head;
        while (second) {
            Node* temp1 = first->next;
            Node* temp2 = second->next;
    
            first->next = second;
            second->next = temp1;
    
            first = temp1;
            second = temp2;
        }
    }
};