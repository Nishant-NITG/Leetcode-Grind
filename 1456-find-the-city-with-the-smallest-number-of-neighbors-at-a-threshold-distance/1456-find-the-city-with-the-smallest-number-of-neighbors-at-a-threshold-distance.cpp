class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // distance matrix with infinity
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        for(int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }

        for(auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            dist[u][v] = w;
            dist[v][u] = w;
        }

        // Floyd-Warshall - CORRECTED
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                        if(dist[i][k] + dist[k][j] < dist[i][j]) {
                            dist[i][j] = dist[i][k] + dist[k][j];  // ✅ FIXED
                        }
                    }
                }
            }
        }

        // find cities with min reachable cities within threshold
        int mincount = n; // max possible
        int resultcity = -1;

        for(int i = 0; i < n; i++) {
            int count = 0;
            for(int j = 0; j < n; j++) {
                if(i != j && dist[i][j] <= distanceThreshold) {
                    count++;
                }
            }

            // update result (prefer larger index for ties)
            if(count <= mincount) {
                mincount = count;
                resultcity = i;
            }
        }

        return resultcity;
    }
};