/*
class Node {
public:
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
    Node* intersectPoint(Node* head1, Node* head2) {
        //  Code Here
        unordered_set<Node*> s; 
        
        Node* temp1=head1;
        while(temp1){
            s.insert(temp1);
            temp1=temp1->next;
        }
        
        Node* temp2=head2;
        while(temp2){
            if(s.find(temp2)!=s.end()){
                return temp2;
            }
            temp2=temp2->next;
        }
        return NULL;
    }
};