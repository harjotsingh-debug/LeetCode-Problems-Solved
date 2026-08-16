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
        if(n==2 && zero==0 && one==1 && two==1) return true;
        if(one==2*zero && two==2*zero) return false ;
        else return true;
    }
};