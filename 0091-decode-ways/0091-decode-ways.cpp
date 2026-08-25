class Solution {
public:
    vector<int> dp;

    int solve(int i, string &s) {

        if(i == s.size())
            return 1;

        if(dp[i] != -1)
            return dp[i];

        // choice 1: take one digit
        int one = 0;

        if(s[i] != '0') {
            one = solve(i + 1, s);
        }

        // choice 2: take two digits
        int two = 0;

        if(i + 1 < s.size()) {

            int num = (s[i] - '0') * 10
                    + (s[i + 1] - '0');

            if(num >= 10 && num <= 26) {
                two = solve(i + 2, s);
            }
        }

        return dp[i] = one + two;
    }

    int numDecodings(string s) {

        dp.assign(s.size(), -1);

        return solve(0, s);
    }
};