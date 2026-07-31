class Solution {
public:
    vector<vector<int>>dp;
    int f(int i,int j,string &text1, string &text2){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(text1[i]==text2[j]) return dp[i][j]=1+f(i-1,j-1,text1,text2);
        return dp[i][j]=max(f(i-1,j,text1,text2),f(i,j-1,text1,text2));
    }
    int longestCommonSubsequence(string text1, string text2) {
        dp.resize(text1.size(),vector<int>(text2.size(),-1));
        return f(text1.size()-1,text2.size()-1,text1,text2);
    }
};