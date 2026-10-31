class Solution {
public:
    const int MOD = 1e9 + 7;

    int f(int i, int j, int dir, vector<vector<int>>& grid,
          vector<vector<vector<int>>>& dp) {

        int m = grid.size();
        int n = grid[0].size();

        // Out of bounds
        if (i >= m || j >= n) return 0;

        // Destination
        if (i == m-1 && j == n-1) return 1;

        // Already calculated
        if (dp[i][j][dir] != -1)
            return dp[i][j][dir];

        int ans = 0;

        if (grid[i][j] == 1) {

            if (dir == 0) {
                // Entered mirror while moving right
                // Reflect down
                ans = f(i+1, j, 1, grid, dp);
            }
            else {
                // Entered mirror while moving down
                // Reflect right
                ans = f(i, j+1, 0, grid, dp);
            }

        }
        else {
            // Empty cell: choose right or down
            int right = f(i, j+1, 0, grid, dp);
            int down = f(i+1, j, 1, grid, dp);

            ans = (right + down) % MOD;
        }

        return dp[i][j][dir] = ans;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(2, -1))
        );

        return f(0, 0, 0, grid, dp);
    }
};