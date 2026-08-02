class Solution {
public:
vector<vector<int>>dp;
bool f(int i,int j,string &s, string &p){
    if(i<0 && j<0) return true;
    if(j<0) return false;
    if(i<0){
        for(int m=j;m>=0;m--){
            if(p[m]!='*') return false;
        }
        return true;
    }

    if(dp[i][j]!=-1) return dp[i][j];
    if(p[j]=='?' || s[i]==p[j]) return dp[i][j]=f(i-1,j-1,s,p);
    if(p[j]=='*') return  dp[i][j]=(f(i,j-1,s,p) ||f(i-1,j,s,p));

    return dp[i][j]=false;

}
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        dp.resize(n,vector<int>(m,-1));
        return f(n-1,m-1,s,p);
    }
};