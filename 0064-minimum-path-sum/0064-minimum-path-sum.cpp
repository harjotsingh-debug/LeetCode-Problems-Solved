class Solution {
public:
vector<vector<int>>dp;
    int f(int i,int j,vector<vector<int>>& grid){
        if(i==0 && j==0) return grid[0][0];
        if(i<0 || j<0) return 1e9;
        if(dp[i][j]!=-1)  return dp[i][j];
        return  dp[i][j]=min(f(i-1,j,grid),f(i,j-1,grid))+grid[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        dp.resize(n,vector<int>(m,-1));
        return f(n-1,m-1,grid);
    }
};