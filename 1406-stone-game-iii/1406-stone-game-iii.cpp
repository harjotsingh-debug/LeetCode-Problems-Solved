class Solution {
public:
vector<int>dp;
    int f(int i,vector<int>& s){
        if(i>=s.size()) return 0;
        if(dp[i]!=-1e9) return dp[i];
        int one=s[i]-f(i+1,s);
        int two=-1e9,three=-1e9;
        if(i+1<s.size())  two=(s[i]+s[i+1])-f(i+2,s);
        if(i+2<s.size())  three=(s[i]+s[i+1]+s[i+2])-f(i+3,s);
        
        return dp[i]=max(one,max(two,three));
    }
    string stoneGameIII(vector<int>& stoneValue) {
        dp.resize(stoneValue.size(),-1e9);
        int n=f(0,stoneValue);
        if(n==0) return "Tie";
        return n>0?"Alice":"Bob";
    }
};