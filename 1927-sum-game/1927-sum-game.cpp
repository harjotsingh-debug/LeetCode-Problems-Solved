class Solution {
public:
    bool sumGame(string s) {
        int n = s.size();

        int half = (n / 2) - 1;

        int q1 = 0, q2 = 0;
        int sl = 0, sr = 0;

        for (int i = 0; i < n; i++) {

            if (s[i] != '?' && i <= half) {
                sl += s[i] - '0';
            }
            else if (s[i] == '?' && i <= half) {
                q1++;
            }
            else if (s[i] != '?' && i > half) {
                sr += s[i] - '0';
            }
            else if (s[i] == '?' && i > half) {
                q2++;
            }
        }

        // No question marks
        if (q1 == 0 && q2 == 0) {
            return sl != sr;
        }

        // Odd number of question marks
        if ((q1 + q2) % 2 == 1) {
            return true;
        }

        // Bob can win only in this case
        if (2 * (sl - sr) == 9 * (q2 - q1)) {
            return false;
        }

        return true;
    }
};