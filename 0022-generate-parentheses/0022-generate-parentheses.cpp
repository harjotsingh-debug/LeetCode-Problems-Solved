class Solution {
public:
    vector<string>ans;
    void f(int open_count,int close_count,int n,string temp){
        if(open_count==n && close_count==n){
            ans.push_back(temp);
            return ;
            }
        if(open_count<n) f(open_count+1,close_count,n,temp+'(');
        if(close_count<open_count) f(open_count,close_count+1,n,temp+')');


    }
    vector<string> generateParenthesis(int n) {

        f(0,0,n,"");
        return ans;
    }
};