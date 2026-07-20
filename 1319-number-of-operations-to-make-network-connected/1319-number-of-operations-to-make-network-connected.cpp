class DisjointSet {
    
public:
vector<int> size,rank,parent;
    int findparent(int node){
        if(parent[node]==node) return node;
        return parent[node]=findparent(parent[node]);
    }
    DisjointSet(int n) {
     size.resize(n,1);
     rank.resize(n,0);
     parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    bool find(int u, int v) {
        return findparent(u)==findparent(v);
    }

    void unionByRank(int u, int v) {
        int pu=findparent(u);
        int pv=findparent(v);
        if(pu == pv) return;
        if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }
        else if(rank[pv]<rank[pu]){
            parent[pv]=pu;
        }
        else{
            parent[pv]=pu;
            rank[pu]++;
        }

    }

    void unionBySize(int u, int v) {
        int pu=findparent(u);
        int pv=findparent(v);
        if(pu==pv) return ;
         if(size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }

    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        DisjointSet d(n) ;
        for(auto & it:connections){
            d.unionByRank(it[0],it[1]);
        }
        int cc=0;
        for(int i=0;i<n;i++){
            if(d.findparent(i)==i){
                cc++;
            }
        }
        return cc-1;

    }
};