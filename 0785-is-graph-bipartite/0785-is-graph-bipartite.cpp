class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();

        vector<int> color(n, -1);

        for(int start = 0; start < n; start++)
        {
            // already processed
            if(color[start] != -1)
                continue;

            queue<int> q;

            q.push(start);

            // Give first color
            color[start] = 0;

            while(!q.empty())
            {
                int node = q.front();
                q.pop();

                for(int neighbor : graph[node])
                {
                    // If uncolored
                    if(color[neighbor] == -1)
                    {
                        // Give opposite color
                        color[neighbor] = 1 - color[node];

                        q.push(neighbor);
                    }

                    // Same color conflict
                    else if(color[neighbor] == color[node])
                    {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};