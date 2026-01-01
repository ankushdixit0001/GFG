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
    int length(Node* head){
        Node* temp=head;
        int count=0;
        while(temp){
            count++;
            temp=temp->next;
        }
        return count;
    }
    Node* intersectPoint(Node* head1, Node* head2) {
        //  Code Here
        int len1=length(head1);
        int len2=length(head2);
        
        Node* temp1=head1;
        Node* temp2=head2;
        
        int diff=abs(len1-len2);
        while(diff--){
            if(len1>len2) temp1=temp1->next;
            else temp2=temp2->next;
        }
        
        while(temp1&&temp2){
            if(temp1==temp2) return temp1;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return nullptr;
    }
};