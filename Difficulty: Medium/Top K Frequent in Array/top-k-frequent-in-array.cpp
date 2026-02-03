class Solution {
  public:
    vector<int> topKFreq(vector<int> &arr, int k) {
        // Code here
        unordered_map<int,int>mpp;
        for(auto &it:arr){
            mpp[it]++;
        }
        // {freq,ele}
        priority_queue<pair<int,int>>q;
        for(auto &it: mpp){
            q.push({it.second,it.first});
        }
        
        vector<int>ans;
        while(k--){
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
        
    
        
    }
};
