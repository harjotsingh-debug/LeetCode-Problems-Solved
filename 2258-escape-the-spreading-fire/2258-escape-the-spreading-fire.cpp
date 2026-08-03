class Solution {
public:
    const int INF = INT_MAX;

    bool isValid(int r, int c, int n, int m) {
        return r >= 0 && c >= 0 && r < n && c < m;
    }

    bool canReach(int wait, vector<vector<int>>& fireTime,
                  vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        // Cannot even stand at the start
        if (wait >= fireTime[0][0])
            return false;

        queue<pair<int, pair<int,int>>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        q.push({wait, {0,0}});
        vis[0][0] = 1;

        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};

        while(!q.empty()){

            auto cur = q.front();
            q.pop();

            int time = cur.first;
            int r = cur.second.first;
            int c = cur.second.second;

            if(r == n-1 && c == m-1)
                return true;

            for(int k=0;k<4;k++){

                int nr = r + dr[k];
                int nc = c + dc[k];

                if(!isValid(nr,nc,n,m))
                    continue;

                if(grid[nr][nc] == 2)
                    continue;

                if(vis[nr][nc])
                    continue;

                int arrive = time + 1;

                // Destination: arrive <= fire
                if(nr == n-1 && nc == m-1){

                    if(arrive <= fireTime[nr][nc]){
                        vis[nr][nc]=1;
                        q.push({arrive,{nr,nc}});
                    }
                }
                else{

                    // Normal cell: arrive < fire
                    if(arrive < fireTime[nr][nc]){
                        vis[nr][nc]=1;
                        q.push({arrive,{nr,nc}});
                    }
                }
            }
        }

        return false;
    }

    int maximumMinutes(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> fireTime(n, vector<int>(m, INF));

        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(grid[i][j]==1){
                    fireTime[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};

        // Multi-source BFS
        while(!q.empty()){

            auto [r,c]=q.front();
            q.pop();

            for(int k=0;k<4;k++){

                int nr=r+dr[k];
                int nc=c+dc[k];

                if(!isValid(nr,nc,n,m))
                    continue;

                if(grid[nr][nc]==2)
                    continue;

                if(fireTime[nr][nc]!=INF)
                    continue;

                fireTime[nr][nc]=fireTime[r][c]+1;

                q.push({nr,nc});
            }
        }

        int low=0;
        int high=1000000000;
        int ans=-1;

        while(low<=high){

            int mid=low+(high-low)/2;

            if(canReach(mid,fireTime,grid)){

                ans=mid;
                low=mid+1;
            }
            else{

                high=mid-1;
            }
        }

        if(ans==1000000000)
            return 1000000000;

        return ans;
    }
};