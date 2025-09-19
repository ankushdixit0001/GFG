/*
The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution {
  public:
    Node *removeDuplicates(Node *head) {
        // your code goes here
        if(!head||!head->next){
            return head;
        }
        
        unordered_set<int> s;
        Node* prev=nullptr;
        Node* curr=head;
        
        while(curr){
            if (s.count(curr->data)) {
                prev->next = curr->next;
                delete curr; // optional: free memory
                curr = prev->next;
            } else {
                s.insert(curr->data);
                prev = curr;
                curr = curr->next;
            }
        }
        
        return head;
    }
};