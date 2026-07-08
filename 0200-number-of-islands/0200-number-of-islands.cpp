class Solution {
public:
int dr[4]={1,-1,0,0};
int dc[4]={0,0,-1,1};
int n=0,m=0;
    void dfs(vector<vector<char>>& grid,int r,int c){
        grid[r][c]='0';
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]=='1'){
                dfs(grid,nr,nc);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
         n=grid.size();
         m=grid[0].size();
        int island=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    island++;
                    dfs(grid,i,j);
                }
            }
        }
        return island;
    }
};