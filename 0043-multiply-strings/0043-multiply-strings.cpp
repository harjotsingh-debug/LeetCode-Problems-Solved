class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.size();
        int m = num2.size();
    if (num1 == "0" || num2 == "0")
    return "0";
        vector<int> ans(n + m, 0);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {

                int a = num1[i] - '0';
                int b = num2[j] - '0';

                int product = a * b;

                int p1 = i + j;
                int p2 = i + j + 1;

                int sum = product + ans[p2];

                ans[p2] = sum % 10;
                ans[p1] += sum / 10;
            }
        }

        string ans1;

        for (int x : ans) {
            if (!(ans1.empty() && x == 0)) {
                ans1 += (x + '0');
            }
        }

        return ans1;
    }
};