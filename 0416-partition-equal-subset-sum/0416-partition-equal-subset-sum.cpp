class Solution {
public:
    vector<vector<int>>dp;
    bool f(int i,vector<int>& nums,int target){
        if(target==0) return true;
        if(i==nums.size()-1) return nums[nums.size()-1]==target;
        if(dp[i][target]!=-1) return dp[i][target];
        bool ntake=f(i+1,nums,target);
        bool take=false;
        if(target>=nums[i]) take=f(i+1,nums,target-nums[i]);
        return dp[i][target]=ntake || take;
    }   
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=nums[i];

        if(sum%2!=0) return false;
        dp.resize(n,vector<int>((sum/2)+1,-1));
        return f(0,nums,sum/2);
    }
};