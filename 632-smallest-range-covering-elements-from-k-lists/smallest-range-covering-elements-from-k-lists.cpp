class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        //create  a min heap
        // pair<int,pair<int,int>>
        // ele , row, col
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>p;
        //create two varibale maximum  and minimum to store currunt 
        // maximum and minimum value
        int minimum,maximum = INT_MIN;
        //fill all the first element of each row in min heap
        for(int i = 0;i<nums.size();i++){
            p.push(make_pair(nums[i][0],make_pair(i,0)));
            //update the maximum varibale
            maximum =max(maximum,nums[i][0]);
        }
        //store smallest value in heap in minimum 
        minimum = p.top().first;

        vector<int>ans(2);//vector storing maximum and minium globally

        ans[0] = minimum;
        ans[1] = maximum;
        pair<int,pair<int,int>>temp;
        int row,col,ele;
        while(p.size()==nums.size()){
            temp = p.top();
            p.pop();
            ele = temp.first;
            row = temp.second.first;
            col = temp.second.second;
            //now push next element of pop element
            if(col+1 < nums[row].size()){
                col++;
                p.push(make_pair(nums[row][col],make_pair(row,col)));
                maximum = max(maximum,nums[row][col]);
                minimum = p.top().first;
            }
            //check that range of currunt elements is lesser than vector element
            if((maximum - minimum)  < (ans[1]-ans[0])){
                ans[0] = minimum;
                ans[1] = maximum;
            }
        }
        return ans;
    }
};