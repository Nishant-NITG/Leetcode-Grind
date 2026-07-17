class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Build adjacency list and calculate in-degrees
        // adj[prereq] = list of courses that depend on prereq
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);
        
        for (auto& pre : prerequisites) {
            int course = pre[0];     // Course we want to take
            int prereq = pre[1];     // Course required first
            adj[prereq].push_back(course);
            inDegree[course]++;      // This course has one more prerequisite
        }
        
        // Find all courses with no prerequisites (in-degree = 0)
        // These are our starting points
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        int taken = 0;
        
        // Kahn's Algorithm: Repeatedly take courses with no prerequisites
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            taken++;
            
            // By taking this course, we remove one prerequisite
            // from all courses that depend on it
            for (int next : adj[course]) {
                inDegree[next]--;
                
                // If this course now has no prerequisites,
                // it's ready to be taken
                if (inDegree[next] == 0) {
                    q.push(next);
                }
            }
        }
        
        // If we couldn't take all courses, there's a cycle
        return taken == numCourses;
    }
};