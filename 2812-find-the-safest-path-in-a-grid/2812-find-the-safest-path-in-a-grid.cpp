class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) {
                    q.push({i,j});
                    dist[i][j]=0;
                }
            }
        }
        int dr[]={1,-1,0,0};
        int dc[]={0,0,-1,1};
        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nc>=0 && nr>=0 && nr<n && nc<m && dist[nr][nc]==-1){
                    dist[nr][nc]=dist[r][c]+1;
                    q.push({nr,nc});
                }
            }
        }
        if(dist[0][0]==0 || dist[n-1][m-1]==0) return 0;

        priority_queue<pair<int,pair<int,int>>>pq;
        vector<vector<int>>vis(n,vector<int>(m,0));
        pq.push({dist[0][0],{0,0}});

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
           int safe=it.first;
            int r=it.second.first;
            int c=it.second.second;
            if(vis[r][c])continue;
            vis[r][c]=1;
            if(r==n-1 && c==m-1) return safe;
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
               if(nc>=0 && nr>=0 && nr<n && nc<m && !vis[nr][nc]){
                    int newsafe=min(safe,dist[nr][nc]);
                    pq.push({newsafe,{nr,nc}});
               }  
            }
        }
        return -1;
    }
};