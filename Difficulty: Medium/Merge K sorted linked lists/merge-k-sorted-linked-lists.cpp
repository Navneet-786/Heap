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

class Comparator{
    public:
        bool operator()(Node* a, Node* b){
            return a->data > b->data;
        }
};
class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        priority_queue<Node*,vector<Node*>, Comparator> pq(arr.begin(),arr.end());//O(n)
        
        Node* head = new Node(0);
        Node* tail = head;
        while(!pq.empty()){
            Node* currNode = pq.top();
            pq.pop();
            //insert next node if exist
            if(currNode->next){
                pq.push(currNode->next);
            }
            
            tail->next = currNode;
            currNode->next = NULL;
            tail = tail->next;
        }
        return head->next;
        
    }
};