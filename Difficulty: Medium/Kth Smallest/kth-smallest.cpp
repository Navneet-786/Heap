class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        if(k>arr.size())return -1;
        //O(n)
        priority_queue<int,vector<int>,greater<int>>q(arr.begin(),arr.end());
        
        while(k>1){
            q.pop();
            k--;
        }
        return q.top();
        
    }
};