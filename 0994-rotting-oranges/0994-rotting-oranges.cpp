class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int fresh=0;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        int min=0;
        while(!q.empty() && fresh>0){
            int sz=q.size();
            while(sz--){
                auto it=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int nrow=it.first+dr[i];
                    int ncol=it.second+dc[i];
                    if(ncol>=0 && nrow>=0 && ncol<m && nrow<n && grid[nrow][ncol]==1){
                        grid[nrow][ncol]=2;
                        q.push({nrow,ncol});
                        fresh--;

                    }
                }
                
            }
            min++;
        }
        return fresh==0?min:-1;
    }
};