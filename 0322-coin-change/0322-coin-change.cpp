class Solution {
public:

    vector<vector<int>> dp;

    int f(int i, int amount, vector<int>& coins){

        if(i == coins.size()){
            if(amount == 0)
                return 0;
            return 1e9;
        }

        if(dp[i][amount] != -1)
            return dp[i][amount];

        int notTake = f(i+1, amount, coins);

        int take = 1e9;

        if(coins[i] <= amount)
            take = 1 + f(i, amount-coins[i], coins);

        return dp[i][amount] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {

        dp.assign(coins.size(), vector<int>(amount+1, -1));

        int ans = f(0, amount, coins);

        return ans >= 1e9 ? -1 : ans;
    }
};