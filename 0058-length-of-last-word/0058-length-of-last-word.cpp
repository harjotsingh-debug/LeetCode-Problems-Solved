class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size();
        int i=n-1;
        int ans=0;
        while(i>=0  &&  s[i]==' ') i--;
        while(i>=0  && s[i]!=' '){
            ans+=1;
            i--;
        }
        return ans;
    }
};