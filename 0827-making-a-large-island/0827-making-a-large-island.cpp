class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n,1);

        for(int i=0;i<n;i++)
            parent[i]=i;
    }

    int findParent(int node){

        if(parent[node]==node)
            return node;

        return parent[node]=findParent(parent[node]);
    }

    void unionBySize(int u,int v){

        int pu=findParent(u);
        int pv=findParent(v);

        if(pu==pv)
            return;

        if(size[pu]<size[pv]){

            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else{

            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }
};

class Solution {
public:

    bool valid(int r,int c,int n){

        return r>=0 && c>=0 && r<n && c<n;
    }

    int largestIsland(vector<vector<int>>& grid) {

        int n=grid.size();

        DisjointSet ds(n*n);

        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        // Connect existing islands
        for(int row=0;row<n;row++){

            for(int col=0;col<n;col++){

                if(grid[row][col]==0)
                    continue;

                for(int k=0;k<4;k++){

                    int nr=row+dr[k];
                    int nc=col+dc[k];

                    if(valid(nr,nc,n) &&
                       grid[nr][nc]==1){

                        int node=row*n+col;
                        int adjNode=nr*n+nc;

                        ds.unionBySize(node,adjNode);
                    }
                }
            }
        }

        int ans=0;

        // Try converting every zero
        for(int row=0;row<n;row++){

            for(int col=0;col<n;col++){

                if(grid[row][col]==1)
                    continue;

                set<int> components;

                for(int k=0;k<4;k++){

                    int nr=row+dr[k];
                    int nc=col+dc[k];

                    if(valid(nr,nc,n) &&
                       grid[nr][nc]==1){

                        components.insert(
                        ds.findParent(nr*n+nc));
                    }
                }

                int sizeTotal=1;

                for(auto parent:components)
                    sizeTotal+=ds.size[parent];

                ans=max(ans,sizeTotal);
            }
        }

        // Edge case: all ones
        for(int i=0;i<n*n;i++){

            ans=max(ans,
            ds.size[ds.findParent(i)]);
        }

        return ans;
    }
};