class Solution {
public:

    int countPaths(int n,
                   vector<vector<int>>& roads)
    {
        const int MOD = 1e9 + 7;

        vector<pair<int,int>> adj[n];

        for(auto &it : roads)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        vector<long long> dist(n, LLONG_MAX);

        vector<long long> ways(n, 0);

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        dist[0] = 0;
        ways[0] = 1;

        pq.push({0,0});

        while(!pq.empty())
        {
            auto [dis,node] = pq.top();
            pq.pop();

            if(dis > dist[node])
                continue;

            for(auto &[neighbor,weight] : adj[node])
            {
                long long newDist =
                dis + weight;

                // Better path found
                if(newDist < dist[neighbor])
                {
                    dist[neighbor] = newDist;

                    ways[neighbor] =
                    ways[node];

                    pq.push(
                    {
                        newDist,
                        neighbor
                    });
                }

                // Another shortest path found
                else if(newDist ==
                        dist[neighbor])
                {
                    ways[neighbor] =
                    (ways[neighbor]
                     + ways[node]) % MOD;
                }
            }
        }

        return ways[n-1] % MOD;
    }
};