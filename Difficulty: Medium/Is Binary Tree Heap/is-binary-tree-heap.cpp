/*
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
  //fin the total numbe rof nodes
  int findLength(Node* root){
      if(!root)return 0;
      return 1 + findLength(root->left) + findLength(root->right);
  }
  
    bool isHeap(Node* tree) {
        if(tree == NULL) return true;

        int length = findLength(tree);
        queue<pair<Node* , pair<int,int>>>q;//{node, {index,length}}
        q.push(make_pair(tree, make_pair(0,length)));
        
        while(!q.empty()){
            Node* currNode = q.front().first;
            int index = q.front().second.first;
            int length = q.front().second.second;
            q.pop();
            if(index >= length)return false;
            
            if(currNode->left){
                if(currNode->data < currNode->left->data)return false;
                q.push({currNode->left, {2*index+1, length}});
            }
            
            if(currNode->right){
                if(currNode->data < currNode->right->data)return false;
                q.push({currNode->right, {2*index+2,length}});
            }
            
        }
        return true;
    }
};