class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        k=k-1;  //0-based indexing

        vector<vector<pair<int,int>>>adj(n);

        for(auto& time:times)
        {
            int u=time[0]-1;
            int v=time[1]-1;
            int w=time[2];
            adj[u].push_back({v,w});

        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        vector<int>dist(n,INT_MAX);
        dist[k]=0;

        pq.push({0,k});

        while(!pq.empty())
        {
         auto [currentdist, currentnode] = pq.top();

            pq.pop();

            if(currentdist>dist[currentnode]) continue;

            for(auto& [neigh,wei]:adj[currentnode])
            {
                int newdist=currentdist+wei;
                if(newdist<dist[neigh])
                {
                    dist[neigh]=newdist;
                    pq.push({newdist,neigh});
                }
            }
        }

        int maxtime=0;
        for(int i=0;i<n;i++)
        {
            if(dist[i]==INT_MAX) return -1;
            maxtime=max(maxtime,dist[i]);
        }

return maxtime;










    }
};