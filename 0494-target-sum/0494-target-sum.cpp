class Solution {
public:
   
    int f(int i,int t,vector<int>& arr,vector<vector<int>>& dp){
    
        if(i==0){
            if(t == 0 && arr[0] == 0) return 2;
            if(t == 0 || t == arr[0]) return 1;
            return 0;
        }
        if(dp[i][t]!=-1) return dp[i][t];
        int npick=f(i-1,t,arr,dp);
        int pick=0;
        if(arr[i]<=t) pick=f(i-1,t-arr[i],arr,dp);
        return dp[i][t]=(npick+pick);
    }
    int countPartitions(vector<int>& arr, int diff) {
        int n = arr.size();
        int sum = 0;

        for(auto it : arr) sum += it;

        if(sum - diff < 0 || (sum - diff) % 2 != 0) return 0;

        int target = (sum - diff) / 2;

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return f(n-1, target, arr, dp);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums,target);
    }
};