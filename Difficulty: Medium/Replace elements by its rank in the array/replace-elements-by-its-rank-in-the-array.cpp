// User function Template for C++

class Solution {
  public:

    vector<int> replaceWithRank(vector<int> &vec, int n) {
        //min priority -queuue
       
        vector<pair<int,int>>temp;
        //phile array bna lo aur fir ek sath insert kr do 
        //time complexity bach jaati hi
        for(int i = 0;i<n;i++){
           temp.push_back({vec[i],i});
        }
        
        
        // O(n)
        priority_queue<pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>>q(temp.begin(),temp.end());
            
        
        int prevElement = -1;
        int prevRank = -1;
        int sortedIndex = 0;
        
        vector<int>ans(n,0);
        
        while(!q.empty()){
            auto [node, currIndex] = q.top();
            q.pop();
            
            int rank = -1;
            //check if element is duplicate
            if(node ==  prevElement){
                rank = prevRank;
            }
            else{
                rank = sortedIndex + 1;
                prevElement = node;
                prevRank = rank;
                sortedIndex++;
            }
            
     
            ans[currIndex] = rank;
            
        }
        return ans;
        
    }
};
