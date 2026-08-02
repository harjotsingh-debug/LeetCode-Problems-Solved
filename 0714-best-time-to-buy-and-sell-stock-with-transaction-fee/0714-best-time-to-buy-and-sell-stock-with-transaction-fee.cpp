class Solution {
public:
    vector<vector<int>>dp;
    int f(int i,int buy,vector<int>& prices,int fee){
        if(i>=prices.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy){
            return  dp[i][buy]=max(-prices[i]+f(i+1,0,prices,fee),f(i+1,1,prices,fee));
        }
        return  dp[i][buy]=max(prices[i]-fee+f(i+1,1,prices,fee),f(i+1,0,prices,fee));
    }
    int maxProfit(vector<int>& prices, int fee) { 
        int n=prices.size();
        dp.resize(n,vector<int>(2,-1));
        return f(0,1,prices,fee);
        
    }
};