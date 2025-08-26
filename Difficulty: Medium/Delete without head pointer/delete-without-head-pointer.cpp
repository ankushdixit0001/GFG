/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}*head;
*/

class Solution {
  public:
    void deleteNode(Node* del_node) {
        // code here
        if(!del_node->next){
            delete del_node;
        }
        Node* nextNode=del_node->next;
        del_node->data=del_node->next->data;
        del_node->next=nextNode->next;
    }
};