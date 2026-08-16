class Solution {
public:

    bool stoneGameIX(vector<int>& stones) {
          int n=stones.size();
         if(n==1) return false;
        int one=0,two=0,zero=0;
        for(int i=0;i<n;i++){
            if(stones[i]%3==0) zero++;
            else if(stones[i]%3==1)one++;
            else if(stones[i]%3==2) two++;
        }

        return (zero % 2 == 0 && one > 0 && two > 0) ||
       (zero % 2 == 1 && abs(one - two) > 2);
    }
};