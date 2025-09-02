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
    Node* swapKth(Node* head, int k) {
        if (!head || !head->next) return head;
    
        int n = 0;
        Node* temp = head;
        while (temp) {
            n++;
            temp = temp->next;
        }
    
        if (k > n) return head;
        if (2 * k - 1 == n) return head; // same node
    
        Node* startPrev = nullptr;
        Node* start = head;
        for (int i = 1; i < k; i++) {
            startPrev = start;
            start = start->next;
        }
    
        Node* endPrev = nullptr;
        Node* end = head;
        for (int i = 1; i < n - k + 1; i++) {
            endPrev = end;
            end = end->next;
        }
    
        if (startPrev) startPrev->next = end;
        if (endPrev) endPrev->next = start;
    
        Node* tempNext = start->next;
        start->next = end->next;
        end->next = tempNext;
    
        if (k == 1) head = end;
        if (k == n) head = start;
    
        return head;
    }
};