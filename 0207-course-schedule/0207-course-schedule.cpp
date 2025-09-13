#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];        // adjacency list
        vector<int> indeg(numCourses, 0);   // indegree of each course
        queue<int> q;

        // Build the graph
        for (auto &p : prerequisites) {
            int u = p[1];  // prerequisite
            int v = p[0];  // course
            adj[u].push_back(v);
            indeg[v]++;
        }

        // Add all courses with indegree 0 to queue
        for (int i = 0; i < numCourses; i++) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;

        // Process courses
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for (int neigh : adj[node]) {
                indeg[neigh]--;      // decrement neighbor indegree
                if (indeg[neigh] == 0)
                    q.push(neigh);
            }
        }

        // If all courses can be processed, no cycle exists
        return (count == numCourses);
    }
};
