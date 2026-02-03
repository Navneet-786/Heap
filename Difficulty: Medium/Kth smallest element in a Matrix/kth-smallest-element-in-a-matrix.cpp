class Solution {
  public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>,greater<pair<int, pair<int,int>>>>pq; //{ele, {row, column}}
        
        
        for(int j = 0; j < mat[0].size();j++){
            pq.push({mat[j][0],{j,0}});
        }
        
        int ans = 0;
        while(k--){
            int ele = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            
            pq.pop();
            
            ans = ele;
            
            if(col+1 < mat.size()){
                pq.push({mat[row][col+1],{row,col+1}});
            }
        }
        
        return ans;
        
    }
};
