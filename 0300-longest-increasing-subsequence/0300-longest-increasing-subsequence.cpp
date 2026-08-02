class Solution {
public:
    vector<vector<int>> dp;
    int f(int i,int prev, vector<int>& nums){
        if(i==nums.size()) return 0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        int ntake=f(i+1,prev,nums);
        int take=0;
        if(prev== -1 || nums[i]>nums[prev]) take=1+f(i+1,i,nums);

        return dp[i][prev+1]=max(take,ntake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n,vector<int>(n,-1));
        return f(0,-1,nums);
    }
};