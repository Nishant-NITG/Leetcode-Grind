#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
      
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto &pre : prerequisites) {
            int u = pre[1];
            int v = pre[0];
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }

       
        vector<int> order;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            order.push_back(course);

            for (int neigh : adj[course]) {
                indegree[neigh]--;
                if (indegree[neigh] == 0) q.push(neigh);
            }
        }

     
        if (order.size() != numCourses) return {};
        return order;
    }
};
