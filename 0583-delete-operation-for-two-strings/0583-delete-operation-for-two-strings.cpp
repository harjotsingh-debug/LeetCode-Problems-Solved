class Solution {
public:
vector<vector<int>>dp;
int f(int i,int j,string &s1,string &s2){
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s1[i]==s2[j]) return dp[i][j]=1+f(i-1,j-1,s1,s2);
    return dp[i][j]=max(f(i-1,j,s1,s2),f(i,j-1,s1,s2));
}
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m =word2.size();
        if(word1 ==word2) return 0;
         dp.resize(n+1,vector<int>(m+1,-1));
        int z=f(n-1,m-1,word1,word2);
        return ((n-z)+(m-z));
    }
};