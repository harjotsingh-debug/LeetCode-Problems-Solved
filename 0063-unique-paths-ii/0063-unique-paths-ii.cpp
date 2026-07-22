class Solution {
public:
vector<vector<int>>dp;
    int f(int i,int j,vector<vector<int>>& obstacleGrid){
        if(i<0 || j<0) return 0;
        if(obstacleGrid[i][j]==1) return 0;
        if(i==0 && j==0)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=f(i-1,j,obstacleGrid)+f(i,j-1,obstacleGrid);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& Grid) {
        int n=Grid.size();
        int m=Grid[0].size();
        dp.resize(n,vector<int>(m,-1));
        return f(n-1,m-1,Grid);
    }
};