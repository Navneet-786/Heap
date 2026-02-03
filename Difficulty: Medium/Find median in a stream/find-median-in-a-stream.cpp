class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        
        vector<double>ans;
        //left side -> max heap
        priority_queue<int>leftpq;
        //right side -> min heap
        priority_queue<int,vector<int>,greater<int>>rightpq;//min heap
         
        for(int i = 0;i<arr.size();i++){
            int currElement = arr[i];
            
            if(leftpq.empty() || currElement <= leftpq.top()){
                leftpq.push(currElement);
            }
            else{
                rightpq.push(currElement);
            }
            
            int n = leftpq.size();
            int m = rightpq.size();
            
            //ensure equilibrium
            if(n>m+1){
                rightpq.push(leftpq.top());
                leftpq.pop();
            }
            else if(m > n){
                leftpq.push(rightpq.top());
                rightpq.pop();
            }
            
            //now equilibruim maintains
            //we are going to find median
            int currSize = leftpq.size() + rightpq.size() ;
            if(currSize&1){
                //odd size
                //choose from leftpq
                ans.push_back(leftpq.top());
            }
            else{
                double res = (leftpq.top() + rightpq.top())/2.0;
                ans.push_back(res);
            }
            
        }
        return ans;
        
    // -------------------------O(n2longn)//brute force------------------
    //   vector<int>temp;
    //   vector<double>ans;
    //   int tempRes = 0;
    //   for(int i = 0;i<arr.size();i++){
    //       temp.push_back(arr[i]);
    //       sort(temp.begin(),temp.end());
           
    //       if(temp.size()&1){
    //           //odd
    //           ans.push_back(temp[temp.size()/2]);
    //       }else{
    //           double val = (temp[temp.size()/2] + temp[temp.size()/2 -1])/2.0;
    //           ans.push_back(val);
    //       }
    //   }
       
    //   return ans;
    }
};
