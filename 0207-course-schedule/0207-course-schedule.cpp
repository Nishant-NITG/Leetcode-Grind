class Solution {
public:

    bool dfs(int node,
             vector<vector<int>>& adj,
             vector<int>& visited,
             vector<int>& pathVisited)
    {
        // Mark visited
        visited[node] = 1;

        // Mark current DFS path
        pathVisited[node] = 1;

        // Traverse neighbors
        for(auto neigh : adj[node])
        {
            // If neighbor unvisited
            if(!visited[neigh])
            {
                if(dfs(neigh, adj, visited, pathVisited))
                {
                    return true;
                }
            }

            // If already in current path
            // cycle exists
            else if(pathVisited[neigh])
            {
                return true;
            }
        }

        // Remove from current path
        pathVisited[node] = 0;

        return false;
    }

    bool canFinish(int numCourses,
                   vector<vector<int>>& prerequisites)
    {
        // Adjacency list
        vector<vector<int>> adj(numCourses);

        // Build graph
        for(auto edge : prerequisites)
        {
            int course = edge[0];
            int prereq = edge[1];

            adj[prereq].push_back(course);
        }

        // Visited array
        vector<int> visited(numCourses, 0);

        // DFS path array
        vector<int> pathVisited(numCourses, 0);

        // Check all components
        for(int i = 0; i < numCourses; i++)
        {
            if(!visited[i])
            {
                if(dfs(i, adj, visited, pathVisited))
                {
                    return false;
                }
            }
        }

        return true;
    }
};