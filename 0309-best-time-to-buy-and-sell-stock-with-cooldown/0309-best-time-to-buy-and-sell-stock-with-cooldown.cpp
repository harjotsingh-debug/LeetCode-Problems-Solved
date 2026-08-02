class Solution {
public:
    vector<vector<int>>dp;
    int f(int i,int buy,vector<int>& prices){
        if(i>=prices.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy){
            return  dp[i][buy]=max(-prices[i]+f(i+1,0,prices),f(i+1,1,prices));
        }
        return  dp[i][buy]=max(prices[i]+f(i+2,1,prices),f(i+1,0,prices));
    }
    int maxProfit(vector<int>& prices) {    
        int n=prices.size();
        dp.resize(n,vector<int>(2,-1));
        return f(0,1,prices);
        
    }
};