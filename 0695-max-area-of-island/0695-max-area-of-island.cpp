class Solution {
public:
vector<vector<int>>vis;
int dr[4]={-1,1,0,0};
int dc[4]={0,0,-1,1};
int n=0,m=0;
    int dfs(int r,int c,vector<vector<int>>& grid){
        vis[r][c]=1;
        
        int area = 1;
        for(int i=0;i<4;i++){
            int nr=dr[i]+r;
            int nc=dc[i]+c;
            if(nr>=0 && nc>=0 && nr<n && nc<m && !vis[nr][nc] && grid[nr][nc]==1){
                area+=dfs(nr,nc,grid);
            }
        }

        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
         n=grid.size();
         m=grid[0].size();
         int island=0;
        vis.resize(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    island=max(island,dfs(i,j,grid));
                }
            }
        }
        return island;
    }
};