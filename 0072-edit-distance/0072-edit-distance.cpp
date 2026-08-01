class Solution {
public:

    vector<vector<int>> dp;

    int f(int i,int j,string &s,string &t){

        if(i<0)
            return j+1;

        if(j<0)
            return i+1;

        if(dp[i][j]!=-1)
            return dp[i][j];

        if(s[i]==t[j])

            return dp[i][j]=
                f(i-1,j-1,s,t);

        int insert=
            1+f(i,j-1,s,t);

        int del=
            1+f(i-1,j,s,t);

        int replace=
            1+f(i-1,j-1,s,t);

        return dp[i][j]=
            min(insert,min(del,replace));
    }

    int minDistance(string word1, string word2) {

        int n=word1.size();
        int m=word2.size();

        dp.assign(n,vector<int>(m,-1));

        return f(n-1,m-1,word1,word2);
    }
};