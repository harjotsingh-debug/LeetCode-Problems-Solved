class Solution {
public:
    vector<vector<int>> dp;

    int f(int i, vector<int>& coins, int t) {

        if (t == 0)
            return 1;

        if (i == coins.size() - 1)
            return (t % coins[i] == 0);

        if (dp[i][t] != -1)
            return dp[i][t];

        int ntake = f(i + 1, coins, t);

        int take = 0;
        if (coins[i] <= t)
            take = f(i, coins, t - coins[i]);

        return dp[i][t] = take + ntake;
    }

    int change(int amount, vector<int>& coins) {
        dp.assign(coins.size(), vector<int>(amount + 1, -1));
        return f(0, coins, amount);
    }
};