class Solution {
public:
    void dfs(int node,vector<vector<int>>& isconnected,vector<int>&vis){
        vis[node]=1;
        for(int i=0;i<isconnected.size();i++){
            if(isconnected[node][i]==1 && !vis[i]){
                dfs(i,isconnected,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>vis(n,0);
        int provinces=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                provinces++;
                dfs(i,isConnected,vis);
            }
        }
        return provinces;
    }
};