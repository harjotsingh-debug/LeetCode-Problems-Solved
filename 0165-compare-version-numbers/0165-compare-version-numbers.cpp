class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream ss1(version1);
        stringstream ss2(version2);

        string part1, part2;

        while (ss1 || ss2) {
            
            int n1 = 0;
            int n2 = 0;

            if (getline(ss1, part1, '.'))
                n1 = stoi(part1);

            if (getline(ss2, part2, '.'))
                n2 = stoi(part2);

            if (n1 < n2)
                return -1;

            if (n1 > n2)
                return 1;
        }

        return 0;
    }
};