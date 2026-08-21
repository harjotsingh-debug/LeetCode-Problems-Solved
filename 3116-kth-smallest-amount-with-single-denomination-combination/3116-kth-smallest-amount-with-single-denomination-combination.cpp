class Solution {
public:

    long long gcd(long long a, long long b) {
        while (b != 0) {
            long long temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }

    // How many valid amounts are <= x?
    long long count(long long x, vector<int>& coins) {

        int n = coins.size();
        long long ans = 0;

        // Generate all subsets of coins
        for (int mask = 1; mask < (1 << n); mask++) {

            long long L = 1;
            int bits = 0;
            bool valid = true;

            for (int i = 0; i < n; i++) {

                // Is coin i present in this subset?
                if (mask & (1 << i)) {

                    bits++;

                    L = lcm(L, coins[i]);

                    // No need to continue if L > x
                    if (L > x) {
                        valid = false;
                        break;
                    }
                }
            }

            if (!valid)
                continue;

            long long multiples = x / L;

            // Odd number of coins -> add
            if (bits % 2 == 1)
                ans += multiples;

            // Even number of coins -> subtract
            else
                ans -= multiples;
        }

        return ans;
    }

    long long findKthSmallest(vector<int>& coins, int k) {

        long long low = 1;

        // Maximum possible answer
        long long mn = *min_element(coins.begin(), coins.end());

        long long high = mn * 1LL * k;

        while (low < high) {

            long long mid = low + (high - low) / 2;

            long long cnt = count(mid, coins);

            if (cnt >= k) {
                // kth number is <= mid
                high = mid;
            }
            else {
                // kth number is > mid
                low = mid + 1;
            }
        }

        return low;
    }
};