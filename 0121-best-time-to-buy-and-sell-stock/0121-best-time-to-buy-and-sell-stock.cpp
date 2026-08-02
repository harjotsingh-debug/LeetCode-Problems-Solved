class Solution {
public:
    // int f(int i,int t,vector<int>& prices){

    //     if(t==0){
    //         int buy 
    //     }
    // }
    int maxProfit(vector<int>& prices) {
        int mini=1e9;
        int ans=0;
        for(int i=0;i<prices.size();i++){
            mini=min(mini,prices[i]);
            ans=max(ans,prices[i]-mini);
        }
        return ans;
    }
};