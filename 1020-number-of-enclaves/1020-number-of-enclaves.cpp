class Solution {
public:
int dr[4]={1,-1,0,0};
int dc[4]={0,0,-1,1};
    void dfs(vector<vector<int>>& grid,int r,int c){
        grid[r][c]=2;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nc>=0 && nr>=0 && nr<n && nc<m && grid[nr][nc]==1){
                dfs(grid,nr,nc);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        for(int i=0;i<n;i++){
            if(grid[i][0]==1){
                dfs(grid,i,0);
            }
            if(grid[i][m-1]==1){
                dfs(grid,i,m-1);
            }
        }
        for(int i=0;i<m;i++){
            if(grid[0][i]==1){
                dfs(grid,0,i);
            }
            if(grid[n-1][i]==1){
                dfs(grid,n-1,i);
            }
        }
        int ones=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    ones++;
                }
            }
        }
        return ones;
    }
};