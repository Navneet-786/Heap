class Solution {
  public:
    int minCost(vector<int>& arr) {
        
      if(arr.size()==1)return 0;
      
      //every time i expect i get min length 
      //so that our cost is min
      priority_queue<int,vector<int>,greater<int>>pq(arr.begin(),arr.end());
      int cost = 0;
      while(pq.size()>1){
          int firstSmall = pq.top();
          pq.pop();
          int secondSmall = pq.top();
          pq.pop();
          
          int resLen = firstSmall + secondSmall;
          cost += resLen;
          pq.push(resLen);
      }
      
      return cost;
      
        
    }
};