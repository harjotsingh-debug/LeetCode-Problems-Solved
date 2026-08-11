class Solution {
public:
    int missingInteger(vector<int>& nums) {
        
        set<int>s;
        for(int num:nums ){
            s.insert(num);
        }
        int ans=nums[0];
        int j=0;
         for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) {
                ans += nums[i];
            } else {
                break;
            }
        }
      while (s.count(ans)) {
            ans++;
        }

        return ans;
    }
};