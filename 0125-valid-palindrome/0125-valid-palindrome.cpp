class Solution {
public:
 int n=0;
    bool palin(string s,string m){
        int l=0,r=n-1;
        while(l<r){
            if(s[l]!=m[r]) return false;
            l++;r--;
        }
        return true;
    }
    bool isPalindrome(string s) {
       n=s.size();
        if(n==0) return true;
        string ans;
        for(char c:s){
            if(isalnum(c)){
                ans+=tolower(c);
            }
        }
        n=ans.size();
        return palin(ans,ans);
    }
};