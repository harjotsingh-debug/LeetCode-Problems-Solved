class Solution {
public:
bool dfs(vector<vector<int>>& graph,vector<int>&color,int i){
    for(int n:graph[i]){
        if(color[n]==-1){
            color[n]=1-color[i];
            if(!dfs(graph,color,n)) return false;
        }
        else if(color[n]==color[i]) return false;
    }
    return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                color[i]=0;
                if(!dfs(graph,color,i)) return false;
            }
        }
        return true;
    }
};