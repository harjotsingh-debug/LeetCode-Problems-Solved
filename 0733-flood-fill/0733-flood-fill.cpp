class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        queue<pair<int,int>>q;
        int ini=image[sr][sc];
        image[sr][sc]=color;
        q.push({sr,sc});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nr=it.first+dr[i];
                int nc=it.second+dc[i];
                if(nc>=0 && nr>=0 && nr<n && nc<m && image[nr][nc]!=color && image[nr][nc]==ini){
                    q.push({nr,nc});
                    image[nr][nc]=color;

                }
            }
        }
        return image;
    }
};