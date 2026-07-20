class DisjointSet {
public:
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findParent(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v) {

        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv)
            return;

        if (rank[pu] < rank[pv])
            parent[pu] = pv;

        else if (rank[pv] < rank[pu])
            parent[pv] = pu;

        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {

        int n = stones.size();

        DisjointSet ds(n);

        for (int i = 0; i < n; i++) {

            for (int j = i + 1; j < n; j++) {

                if (stones[i][0] == stones[j][0] ||
                    stones[i][1] == stones[j][1]) {

                    ds.unionByRank(i, j);
                }
            }
        }

        int components = 0;

        for (int i = 0; i < n; i++) {
            if (ds.findParent(i) == i)
                components++;
        }

        return n - components;
    }
};