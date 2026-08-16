class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        string ans;
        vector<string>rev;
        while(ss>>word){
            rev.push_back(word);
        }
        for(int i=rev.size()-1;i>=0;i--){
            ans+=rev[i];
            if(i!=0){
                ans+=' ';
            }
        }
        return ans;
    }
};