class Solution {
public:
vector<vector<int>>dp;
int f(int i,int j,vector<int>& piles){
    if(i==j) return piles[i];
    if(dp[i][j]!=-1e9) return dp[i][j];
    int left=piles[i]-f(i+1,j,piles);
    int right=piles[j]-f(i,j-1,piles);
    return dp[i][j]=max(left,right);
}
    bool stoneGame(vector<int>& piles) {
        // int n=piles.size();
        // dp.resize(n,vector<int>(n,-1e9));
        // return f(0,n-1,piles)>=0;
        return true;
    }
};