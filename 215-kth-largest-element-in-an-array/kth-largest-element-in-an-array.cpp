class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       int ans = 0;
       priority_queue<int>q;
       for(auto &it:nums){
        q.push(it);
       }

       while(k--){
        ans = q.top();
        q.pop();
       }
       return ans;
    }
};