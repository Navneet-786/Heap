// User function template for C++

class Solution {
  public:
    string isKSortedArray(int arr[], int n, int k) {
        priority_queue<pair<int,int>,
                    vector<pair<int,int>>,
                    greater<pair<int,int>>>q;
                    // {node, index}
        for(int i = 0;i<n;i++){
            q.push({arr[i],i});
        }
        
        for(int i = 0;i<n;i++){
            int expectedIndex = i;
            int currIndex = q.top().second;
            q.pop();
            
            int diff = abs(expectedIndex - currIndex);
            if(diff > k)return "No";
        }
        
        return "Yes";
    }
};