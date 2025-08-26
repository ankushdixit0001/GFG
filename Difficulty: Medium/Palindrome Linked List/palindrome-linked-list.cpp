/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
       data = x;
       next = NULL;
    }
};
*/

class Solution {
  public:
    bool isPalindrome(Node *head) {
        //  code here
        //edge case: empty or single Node
        if(!head||!head->next) return true;
        
        stack<int> s;
        Node* slow=head;
        Node* fast=head; 
        
        //pushing data
        while(fast&&fast->next){
            s.push(slow->data);
            slow=slow->next;
            fast=fast->next->next;
        }
        
        // If odd number of nodes, skip the middle one
        if (fast) slow = slow->next;
        
        //compairing second half
        while(slow){
            if(slow->data!=s.top()) return false;
            s.pop();
            slow=slow->next;
        }
        
        return true;
    }
};