class Solution {
public:
    int f(int i,int j,string &s){
        if(i>=j) return 1;
        
        if(s[i]!=s[j]) return 0;
        return f(i+1,j-1,s);
    }
    int countSubstrings(string s) {
        int n=s.size();
        int no=0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = i; j < s.length(); j++) {
                string m=s.substr(i, j - i + 1);
               if(f(0,m.size()-1,m)) no++;
    
     }
        }
        return no;
    }
};