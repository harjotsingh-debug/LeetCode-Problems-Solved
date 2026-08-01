class Solution {
public:
vector<vector<int>>dp;
int f(int i,int j,vector<int>& nums){
        if(i==j) return nums[i];
        if(dp[i][j]!=-1e9)return  dp[i][j];
        int left=nums[i]-f(i+1,j,nums);
        int right=nums[j]-f(i,j-1,nums);
        return dp[i][j]=max(left,right);
}
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n,vector<int>(n,-1e9));
        return f(0,n-1,nums)>=0;
    }
};