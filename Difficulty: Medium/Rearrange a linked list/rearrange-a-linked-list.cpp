/* Node structure

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
    void rearrangeEvenOdd(Node *head) {
        // Your Code here
        
        Node* dummyOdd=new Node(-1);
        Node* dummyEven=new Node(-1);
        
        Node* odd=dummyOdd;
        Node* even=dummyEven;
        
        Node* curr=head;
        while(curr){
            odd->next=curr;
            odd=odd->next;
            curr=curr->next;
            
            if(curr){
                even->next=curr;
                even=even->next;
                curr=curr->next;
            }
        }
        odd->next=nullptr;
        even->next=nullptr;
        
        odd->next=dummyEven->next;
        
        head=dummyOdd->next;
        
        delete dummyOdd;
        delete dummyEven;
    }
};