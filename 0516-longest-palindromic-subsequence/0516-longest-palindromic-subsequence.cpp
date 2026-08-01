class Solution {
public:
vector<vector<int>>dp;
int f(int i,int j,string &s1,string &s2){
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s1[i]==s2[j]) return dp[i][j]=1+f(i-1,j-1,s1,s2);
    return dp[i][j]=max(f(i-1,j,s1,s2),f(i,j-1,s1,s2));
}
    int longestPalindromeSubseq(string s) {
        string s2=s;
        reverse(s2.begin(),s2.end());
        dp.resize(s.size()+1,vector<int>(s.size()+1,-1));
        return f(s.size()-1,s.size()-1,s,s2);
    }
};