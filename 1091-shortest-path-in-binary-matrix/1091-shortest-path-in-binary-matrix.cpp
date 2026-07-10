class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        queue<pair<int,int>>q;
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        q.push({0,0});
        dist[0][0]=1;
        int dr[]={-1,-1,-1,0,1,1,1,0};
        int dc[]={-1,0,1,1,1,0,-1,-1};
        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();
            if(r==n-1 && c==n-1) return dist[r][c];
            for(int i=0;i<8;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nc>=0 && nr>=0 && nc<n && nr<n && grid[nr][nc]==0 && dist[nr][nc]==1e9){
                    dist[nr][nc]=dist[r][c]+1;
                    q.push({nr,nc});
                }
            }
        }
        return -1;
    }
};