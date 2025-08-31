/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/

class Solution {
  public:
    Node* segregate(Node* head) {
        // Edge case check — O(1) time, O(1) space
        if (!head || !head->next) {
            return head;
        }

        // Dummy nodes for 0s, 1s, and 2s — O(1) space, O(1) time
        Node* dummyZero = new Node(-1);  // O(1)
        Node* dummyOne  = new Node(-1);  // O(1)
        Node* dummyTwo  = new Node(-1);  // O(1)

        // Tail pointers for each list — O(1) space, O(1) time
        Node* tailZero = dummyZero;      // O(1)
        Node* tailOne  = dummyOne;       // O(1)
        Node* tailTwo  = dummyTwo;       // O(1)

        // Traversal pointer — O(1) space
        Node* curr = head;               // O(1)

        // Traverse and segregate nodes — O(n) time, O(1) space
        while (curr) {
            if (curr->data == 0) {
                tailZero->next = curr;
                tailZero = tailZero->next;
            } else if (curr->data == 1) {
                tailOne->next = curr;
                tailOne = tailOne->next;
            } else {
                tailTwo->next = curr;
                tailTwo = tailTwo->next;
            }
            curr = curr->next;
        }

        // Final connections — O(1) time, O(1) space
        tailZero->next = dummyOne->next? dummyOne->next : dummyTwo->next;
        tailOne->next = dummyTwo->next;
        tailTwo->next = NULL;

        // Set new head — O(1) time
        head = dummyZero->next;

        // Delete dummy nodes — O(1) time, frees O(1) space
        delete dummyZero;
        delete dummyOne;
        delete dummyTwo;

        // Final time complexity: O(n)
        // Final space complexity: O(1)
        return head;
    }
};