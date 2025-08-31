/* structure for a node
class Node {
 public:
  int data;
  Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
}; */

class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        Node* newNode = new Node(data);
    
        // Case 1: Empty list
        if (!head) {
            newNode->next = newNode;
            return newNode;
        }
    
        Node* curr = head;
    
        // Case 2: Insert before head (new minimum)
        if (data <= head->data) {
            // Find the last node to update its next
            while (curr->next != head) {
                curr = curr->next;
            }
            curr->next = newNode;
            newNode->next = head;
            return newNode; // new head
        }
    
        // Case 3: Insert somewhere after head
        while (curr->next != head && curr->next->data < data) {
            curr = curr->next;
        }
    
        // Insert newNode between curr and curr->next
        newNode->next = curr->next;
        curr->next = newNode;
        return head;
    }
};