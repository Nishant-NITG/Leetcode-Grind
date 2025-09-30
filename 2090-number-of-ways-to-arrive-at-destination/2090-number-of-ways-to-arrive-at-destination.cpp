class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int mod=1e9+7;

        //adj list banate h
        vector<vector<pair<int, int>>> graph(n);
        for (auto& road : roads) {
            int u = road[0], v = road[1], time = road[2];
            graph[u].push_back({v, time});
            graph[v].push_back({u, time});
        }

        vector<long long>dist(n,LLONG_MAX);
        vector<long long>ways(n,0);


        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;

        dist[0]=0;
        ways[0]=1;

        pq.push({0,0});

        while(!pq.empty())
        {
            auto[currentdist,currentnode]=pq.top();
            pq.pop();

            if(currentdist>dist[currentnode]) continue;

            for(auto& [neigh,wei]:graph[currentnode])
            {
                long long newdist=currentdist+wei;

                if(newdist<dist[neigh])
                {
                    dist[neigh]=newdist;
                    ways[neigh]=ways[currentnode];
                    pq.push({newdist,neigh});


                }
                else if(newdist==dist[neigh])
                {
                    ways[neigh]=(ways[currentnode]+ways[neigh])%mod;
                }
            }
        }

        return ways[n-1]%mod;
    }
};