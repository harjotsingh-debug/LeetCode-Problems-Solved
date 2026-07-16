class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        const int INF = 1e9;

        vector<vector<int>> dist(n, vector<int>(n, INF));

        for (int i = 0; i < n; i++)
            dist[i][i] = 0;

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            dist[u][v] = wt;
            dist[v][u] = wt;
        }

        // Floyd-Warshall
        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][via] == INF || dist[via][j] == INF)
                        continue;

                    dist[i][j] = min(dist[i][j],
                                     dist[i][via] + dist[via][j]);
                }
            }
        }

        int ans = -1;
        int mini = INT_MAX;

        for (int city = 0; city < n; city++) {

            int cnt = 0;

            for (int adj = 0; adj < n; adj++) {
                if (dist[city][adj] <= distanceThreshold)
                    cnt++;
            }

            if (cnt <= mini) {
                mini = cnt;
                ans = city;
            }
        }

        return ans;
    }
};