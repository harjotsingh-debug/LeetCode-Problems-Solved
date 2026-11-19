class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi=-1e9;
        int running_sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            running_sum+=nums[i];
            maxi=max(maxi,running_sum);
            if(running_sum<0){
                running_sum=0;
            }
        }
        return maxi;
    }
};