class Solution {
  public:
    long long sumBetweenTwoKth(long long arr[], long long n, long long k1, long long k2) {

        priority_queue<int,vector<int>, greater<int>>pq(arr, arr+ n);
        int N = k2-k1-1;
        while(k1--){
            pq.pop();
        }
        long long ans = 0;
        
        while(N--){
            ans+= pq.top();
            pq.pop();
        }
        return ans;
    }
};