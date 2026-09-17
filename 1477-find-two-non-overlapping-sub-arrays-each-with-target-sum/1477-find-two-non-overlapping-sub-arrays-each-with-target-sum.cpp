class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {

        int n = arr.size();
        const int INF = 1e9;

        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + arr[i];

        // dp[i] = minimum length of one valid subarray
        // completely inside first i elements
        vector<int> dp(n + 1, INF);

        unordered_map<int, int> mp;

        // prefix sum -> index
        mp[0] = 0;

        int ans = INF;

        for (int i = 1; i <= n; i++) {

            // Don't use arr[i-1]
            dp[i] = dp[i - 1];

            int needed = prefix[i] - target;

            if (mp.count(needed)) {

                int j = mp[needed];

                // subarray [j, i-1]
                int len = i - j;

                // Previous subarray must be inside first j elements
                if (dp[j] != INF) {
                    ans = min(ans, dp[j] + len);
                }

                // This is also a possible single subarray
                dp[i] = min(dp[i], len);
            }

            // Keep earliest occurrence
            if (!mp.count(prefix[i]))
                mp[prefix[i]] = i;
        }

        return ans == INF ? -1 : ans;
    }
};