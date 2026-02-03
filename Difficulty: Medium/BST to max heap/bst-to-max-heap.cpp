// User function Template for C++

/*struct Node {
    int data;
    Node *left, *right;
};*/

class Solution {
  public:
  void findInorder(Node* root,vector<int>&inorder){
      if(!root)return;
      
      findInorder(root->left, inorder);
      inorder.push_back(root->data);
      findInorder(root->right, inorder);
  }
  void postorder(Node* root, vector<int>&vec, int &index){
      if(!root)return;
      
      postorder(root->left, vec, index);
      postorder(root->right, vec, index);
      root->data = vec[index];
      index++;
  }
    void convertToMaxHeapUtil(Node* root) {
        
        if(root->left ==NULL && root->right == NULL )return;
        
        vector<int>inorder;
        //inorder
        findInorder(root, inorder);
        int index = 0;
        postorder(root, inorder, index);
    }
};
