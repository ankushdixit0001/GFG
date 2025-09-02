// User function template for C++

/*
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
    Node* divide(Node* head) {
        // code here
        if(!head||!head->next){
            return head;
        }
        //create dummy heads for even and odd lists
        Node* dummyEven=new Node(-1);
        Node* dummyOdd=new Node(-1); 
        Node* even=dummyEven;
        Node* odd=dummyOdd;
        
        Node* temp=head;
        
        //partition nodes into even odd lists
        while(temp){
            if(temp->data%2==0){
                even->next=temp;
                even=temp;
            } else {
                odd->next=temp;
                odd=temp;
            }
            temp=temp->next;
        }
        
        // Terminate odd list to avoid cycles
        odd->next=NULL;
        
        // Merge even and odd lists
        even->next=dummyOdd->next;
        
        // Set new head and clean up dummy nodee
        head=dummyEven->next;
        delete dummyEven;
        delete dummyOdd;
        
        return head;
        
    }
};