class Solution {
public:
    // DFS helper that explores all cities in a province
    void dfs(int city, vector<vector<int>>& isConnected, vector<bool>& visited) {
        // Mark current city as part of this province
        visited[city] = true;
        int n = isConnected.size();
        
        // Instead of having an adjacency list, we scan the entire row
        // This is O(n) per vertex, which is fine for n <= 200
        for (int neighbor = 0; neighbor < n; neighbor++) {
            // Check if there's a direct connection to this neighbor
            // AND we haven't visited it yet
            if (isConnected[city][neighbor] == 1 && !visited[neighbor]) {
                // If connected, it belongs to the same province
                dfs(neighbor, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int provinces = 0;
        
        // Iterate through all cities
        for (int i = 0; i < n; i++) {
            // If this city hasn't been visited, it starts a new province
            if (!visited[i]) {
                provinces++;
                
                // Explore the entire province from this city
                dfs(i, isConnected, visited);
            }
        }
        
        return provinces;
    }
};