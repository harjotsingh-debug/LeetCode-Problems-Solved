class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini =1e9,maxi=-1e9,minii=-1,maxii=-1;
        int n=nums.size();
        if(n==1) return 1;
        for(int i=0;i<n;i++){
            if(maxi<nums[i]){
                maxi=nums[i];
                maxii=i;
            }
             if(mini>nums[i]){
                mini=nums[i];
                minii=i;
            }
        }
       int left = max(minii, maxii) + 1;

        int right = n - min(minii, maxii);

        int both = min(minii, maxii) + 1 + n - max(minii, maxii);

        return min({left, right, both});
    }
};