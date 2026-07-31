class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int m = nums.size();
        int n = m / 2;

        vector<int> left(nums.begin(), nums.begin() + n);
        vector<int> right(nums.begin() + n, nums.end());

        vector<vector<int>> L(n + 1), R(n + 1);

        // Left subset sums
        for (int mask = 0; mask < (1 << n); mask++) {
            int sum = 0;
            int cnt = 0;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    sum += left[i];
                    cnt++;
                }
            }

            L[cnt].push_back(sum);
        }

        // Right subset sums
        for (int mask = 0; mask < (1 << n); mask++) {
            int sum = 0;
            int cnt = 0;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    sum += right[i];
                    cnt++;
                }
            }

            R[cnt].push_back(sum);
        }

        for (int i = 0; i <= n; i++)
            sort(R[i].begin(), R[i].end());

        int total = accumulate(nums.begin(), nums.end(), 0);
        int ans = INT_MAX;

        for (int k = 0; k <= n; k++) {

            for (int x : L[k]) {

                auto &vec = R[n - k];

                int target = total / 2 - x;

                auto it = lower_bound(vec.begin(), vec.end(), target);

                if (it != vec.end()) {
                    int chosen = x + *it;
                    ans = min(ans, abs(total - 2 * chosen));
                }

                if (it != vec.begin()) {
                    --it;
                    int chosen = x + *it;
                    ans = min(ans, abs(total - 2 * chosen));
                }
            }
        }

        return ans;
    }
};