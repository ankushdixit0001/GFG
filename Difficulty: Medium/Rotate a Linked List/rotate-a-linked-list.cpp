/*
class Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* rotate(Node* head, int k) {
        if (!head || k == 0) return head;
    
        // Step 1: Find length and tail
        Node* tail = head;
        int len = 1;
        while (tail->next) {
            tail = tail->next;
            len++;
        }
    
        // Step 2: Normalize k
        k = k % len;
        if (k == 0) return head;
    
        // Step 3: Make list circular
        tail->next = head;
    
        // Step 4: Move to new tail (len - k steps for right rotation)
        Node* newTail = head;
        for (int i = 1; i < k; i++) {
            newTail = newTail->next;
        }
    
        // Step 5: Break the circle
        Node* newHead = newTail->next;
        newTail->next = nullptr;
    
        return newHead;
    }
};