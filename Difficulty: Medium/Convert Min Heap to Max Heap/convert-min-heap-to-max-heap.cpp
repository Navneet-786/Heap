// User function Template for C++

class Solution {
  public:
  void heapyfy(int index, vector<int>&vec){
      //we are focus to make parent greater
      int largest = index;
      int left  = 2* index + 1;
      int right = 2* index + 2;
      
      if(left < vec.size() && vec[left] > vec[largest]){
          largest = left;
      }
      if(right < vec.size() && vec[right] > vec[largest]){
          largest = right;
      }
      
      if(largest != index){
          swap(vec[largest], vec[index]);
          heapyfy(largest, vec);
      }
      
  }
    void convertMinToMaxHeap(vector<int> &vec, int n) {
        //first non leaf node
        int nonLeafNodeIndex = (n/2) - 1;
        
        for(int i = nonLeafNodeIndex;i>=0;i--){
            heapyfy(i,vec);
        }
    }
};
