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
 struct Comparator {
    bool operator()(Node* a, Node* b) {
        return a->data > b->data; // MIN HEAP
    }
};
    Node* mergeKLists(vector<Node*>& arr) {
       //put all element in priority queueu(min heap)
       priority_queue<Node*,
                    vector<Node*>,
                    Comparator>q(arr.begin(),arr.end());
                    
        Node* root = new Node(-1);
        Node* currNode = root;
        
        while(!q.empty()){
            
            Node* temp = q.top();
            q.pop();
            //make it node
            currNode->next = temp;
            currNode = currNode->next;
            
            //if temp have next Node then insert into queue
            if(temp->next!=NULL){
                q.push(temp->next);
            }
        }
        
        return root->next;
        
        
    }
};