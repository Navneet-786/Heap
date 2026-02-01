class Solution {
  public:
    int heapHeight(int n, int arr[]) {
        int count = 0;
        if(n==1)return 1;
        while(n>1){
            count++;
            n/=2;
        }
        
        return count;
        
    }
};