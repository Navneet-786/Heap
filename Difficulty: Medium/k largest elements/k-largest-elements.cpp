class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        // Your code here
        vector<int>ans;
        if(k> arr.size())return ans;
        
        priority_queue<int>q(arr.begin(), arr.end());
        while(k>0){
            int ele = q.top();
            q.pop();
            
            ans.push_back(ele);
            
            k--;
        }
        
        return  ans;
    }
};