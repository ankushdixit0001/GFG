/*
  reverse alternate nodes and append at the end
  The input list will have at least one element
  Node is defined as
  struct Node
  {
      int data;
      struct Node *next;

      Node(int x){
        data = x;
        next = NULL;
      }

   };

*/
class Solution {
  public:
    Node* reverse(Node* head){
        if(!head||!head->next){
            return head; //base case: empty or single node
        }
        
        Node* prev=nullptr;
        Node* curr=head;
        Node* next=nullptr;
        
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        
        return prev; //new head of reversed list
    }
    
    void rearrange(Node* head) {
        // add code here
        
        //dummy nodes to build two separate lists
        Node* list1=new Node(-1);
        Node* list2=new Node(-1);
        
        Node* tail1=list1;//tail for even positioned nodes(0 based index)
        Node* tail2=list2;// tail for odd positioned nodes
        
        Node* curr=head;
        
        // Split the original list into two: even-indexed and odd-indexed nodes
        while(curr){
            tail1->next=curr;
            tail1=tail1->next;
            curr=curr->next; 
            
            if(curr){
                tail2->next=curr;
                tail2=tail2->next;
                curr=curr->next;
            }
        }
        
        //terminate the both list
        tail1->next=nullptr;
        tail2->next=nullptr;
        
        //reverse list
        tail1->next=reverse(list2->next);
        
        //update the original head
        head=list1->next;
        
        //clean up dummy Node
        delete list1;
        delete list2;
    }
};