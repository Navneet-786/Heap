class Solution {
  public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        
        int cols = mat[0].size(); //number of cols
        int rows = mat.size(); //number of rows
        
        vector<pair<int,pair<int,int>>>temp;
        int i = 0;
        for(auto &it:mat){
            temp.push_back({mat[i][0],{i,0}});
            i++;
        }
        // {ele, {x, y}}
        priority_queue<pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
            >q(temp.begin(),temp.end());
            
        vector<int>ans;
        while(!q.empty()){
            
            auto [currEle,coords] = q.top();
            int currX = coords.first;
            int currY = coords.second;
            q.pop();
            
            //push into ans
            ans.push_back(currEle);
            
            if(currY+1 == cols)continue;
            q.push({mat[currX][currY+1],{currX, currY+1}});
        }
        
        return ans;
    }
};