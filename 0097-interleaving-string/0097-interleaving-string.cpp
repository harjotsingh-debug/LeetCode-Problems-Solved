class Solution {
public:
    vector<vector<int>> dp;

    bool solve(int i, int j, string &s1, string &s2, string &s3) {

        // We have used all characters
        if(i == s1.size() && j == s2.size())
            return true;

        // Already calculated
        if(dp[i][j] != -1)
            return dp[i][j];

        bool ans = false;

        // Take character from s1
        if(i < s1.size() && s1[i] == s3[i + j]) {
            ans = solve(i + 1, j, s1, s2, s3);
        }

        // Take character from s2
        if(!ans && j < s2.size() && s2[j] == s3[i + j]) {
            ans = solve(i, j + 1, s1, s2, s3);
        }

        return dp[i][j] = ans;
    }

    bool isInterleave(string s1, string s2, string s3) {

        if(s1.size() + s2.size() != s3.size())
            return false;

        dp.assign(s1.size() + 1,
                 vector<int>(s2.size() + 1, -1));

        return solve(0, 0, s1, s2, s3);
    }
};