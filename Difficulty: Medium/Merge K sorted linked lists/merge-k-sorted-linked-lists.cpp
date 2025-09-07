/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    struct compare{
        bool operator()(Node* a, Node* b){
            return a->data > b->data;
        }
    };
    
    Node* mergeKLists(vector<Node*>& arr) {
        // code here
        Node* newHead=new Node(-1);
        priority_queue<Node*, vector<Node*>, compare>pq;
        
        //push the head of each list in pq
        for(int i=0;i<arr.size();i++){
            pq.push(arr[i]);
        }
        
        Node* temp=newHead;
        
        //extract the smallest node and push its next
        while(!pq.empty()){
            Node* top=pq.top();
            pq.pop();
            
            temp->next=top;
            temp=temp->next;
            
            if(top->next) pq.push(top->next);
        }
        
        Node* res=newHead->next;
        delete newHead;
        return res;
    }
};