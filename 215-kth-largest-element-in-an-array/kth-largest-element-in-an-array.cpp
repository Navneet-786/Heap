class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       int ans = 0;
       priority_queue<int>q(nums.begin(), nums.end());
       while(k--){
        ans = q.top();
        q.pop();
       }
       return ans;
    }
};