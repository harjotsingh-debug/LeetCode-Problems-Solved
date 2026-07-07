class Solution {
public:
    int dr[4]={-1,1,0,0};
    int dc[4]={0,0,-1,1};
    void dfs(vector<vector<char>>& board,int r,int c){
        int n=board.size();
        int m=board[0].size();
        board[r][c]='#';
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nc>=0 && nr>=0 && nr<n && nc<m && board[nr][nc]=='O'){
                dfs(board,nr,nc);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                dfs(board,i,0);
            }
            if(board[i][m-1]=='O'){
                dfs(board,i,m-1);
            }
        }
        for(int i=0;i<m;i++){
            if(board[0][i]=='O'){
                dfs(board,0,i);
            }
            if(board[n-1][i]=='O'){
                dfs(board,n-1,i);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                else if(board[i][j]=='#'){
                    board[i][j]='O';
                }
            }
        }

    }
};