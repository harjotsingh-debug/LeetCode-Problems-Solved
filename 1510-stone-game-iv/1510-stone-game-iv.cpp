class Solution {
public:
    bool solve(int n, vector<int>& dp) {
        if (n == 0)
            return false;

        if (dp[n] != -1)
            return dp[n];

        for (int i = 1; i * i <= n; i++) {
            int square = i * i;

            // If opponent loses, I win
            if (!solve(n - square, dp)) {
                return dp[n] = true;
            }
        }

        // No winning move
        return dp[n] = false;
    }

    bool winnerSquareGame(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};