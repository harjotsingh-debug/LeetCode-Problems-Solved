class Solution {
public:
    vector<vector<vector<int>>>dp;
    int f(int i,int buy,int cap,vector<int>& prices){
        if(i==prices.size()) return 0;
        if(cap==0) return 0;
        if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];
        if(buy){
            return dp[i][buy][cap]=max(-prices[i]+f(i+1,0,cap,prices),f(i+1,1,cap,prices));
        }
        return dp[i][buy][cap]=max(prices[i]+f(i+1,1,cap-1,prices),f(i+1,0,cap,prices));
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        dp.assign(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return f(0,1,2,prices);
    }
};