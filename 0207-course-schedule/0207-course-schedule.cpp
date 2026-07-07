class Solution {
public:
    bool canFinish(int v, vector<vector<int>>& pre) {
        vector<vector<int>>adj(v);
        vector<int>indegree(v,0);
        for(auto &it: pre){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        queue<int>q;
        for(int i=0;i<v;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int done=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            done++;
            for(int x : adj[node]){
                indegree[x]--;
                if(indegree[x]==0){
                    q.push(x);
                }
            }
        }
        return done==v;
    }
};