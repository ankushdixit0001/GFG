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
    int lengthOfLoop(Node *head) {
        // code here
        Node* slow=head;
        Node* fast=head;
        
        while(fast&&fast->next){
            
            slow=slow->next;
            fast=fast->next->next; 
            
            if(slow==fast){ 
                
                int count=1;
                Node* curr=slow->next;
                
                while(curr!=slow){
                    curr=curr->next;
                    count++;
                }
                
                return count;
            }
        }
        return 0;
    }
};