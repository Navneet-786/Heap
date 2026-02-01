
class Solution {
  public:
    bool isMaxHeap(int arr[], int n) {
       //level order traversal only plays here
       //that you have to check the heap property
       //max-heap=> parent>= child nodes
       
       for(int  i =0;i<n/2;i++){
           int parent = arr[i];
           int left = 2* i + 1;
           int right = 2* i+2;
           
           if(left < n && parent < arr[left])return false;
           if(right < n && parent < arr[right])return false;
       }
       return true;
    }
};