class Solution {
public:
    int findSquareRoot(long long num){
        long long ans = 1;
        for(long long i = 1;i<= num/2;i++){
            if(i*i  <= num){
                ans = max(ans, i);
                
            }
            else{
                break;
            }
        }
        return ans;
    }
    long long pickGifts(vector<int>& gifts, int k) {
       priority_queue<long long>q;
       for(auto &it:gifts){
            q.push(it);
       }

       while(k--){
        long long gift = q.top();
        q.pop();
        long long rem = findSquareRoot(gift);
        
        q.push(rem);
       }

       long long ans = 0;
       while(!q.empty()){
        ans+=q.top();
        q.pop();
       }
       return ans;


    }
};