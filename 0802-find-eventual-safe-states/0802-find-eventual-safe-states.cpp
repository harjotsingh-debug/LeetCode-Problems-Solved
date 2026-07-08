class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) { 
        int n=graph.size();
          vector<int>outdegree(n,0);
          vector<vector<int>>rev(n);
          for(int i=0;i<n;i++){
            outdegree[i]=graph[i].size();
            for(int x:graph[i]){
                rev[x].push_back(i);
            }
          }
          queue<int>q;
          for(int i=0;i<n;i++){
                if(outdegree[i]==0){
                    q.push(i);
                }
          }
          vector<int>ans;
          while(!q.empty()){
            int node=q.front();
            ans.push_back(node);
            q.pop();
            for(int x:rev[node]){
                outdegree[x]--;
                if(outdegree[x]==0){
                    q.push(x);
                }
            }
          }
          sort(ans.begin(),ans.end());
          return ans;

    }
};