class Solution {
public:
    int n=0;
    vector<vector<int>>dp;
    vector<vector<bool>> vis;
int f(int i,int j,vector<vector<int>>& triangle){
    if(i==n-1)return triangle[i][j];
    if (vis[i][j])
        return dp[i][j];

    vis[i][j] = true;

    return dp[i][j]=min(f(i+1,j,triangle),f(i+1,j+1,triangle))+triangle[i][j];

}
    int minimumTotal(vector<vector<int>>& triangle) {
        n=triangle.size();
        dp.resize(n,vector<int>(n,-1));
         vis.assign(n, vector<bool>(n, false));
        return f(0,0,triangle);
    }
};