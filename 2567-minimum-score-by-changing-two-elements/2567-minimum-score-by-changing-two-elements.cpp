class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int change_smallest=abs(nums[2]-nums[n-1]);
        int change_greatest=abs(nums[n-3]-nums[0]);
        int change_both=abs(nums[1]-nums[n-2]);
        int high_score=min(change_smallest,min(change_greatest,change_both));
        return high_score;
    }
};