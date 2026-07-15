class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // BLOCK 1: Create storage for all nodes
        // Each node stored as (column, row, value)
        vector<tuple<int, int, int>> nodes;
        
        // BLOCK 2: Visit every node and save its coordinates
        collectNodes(root, 0, 0, nodes);
        
        // BLOCK 3: Sort everything
        // Sorts by column first, then row, then value
        sort(nodes.begin(), nodes.end());
        
        // BLOCK 4: Group by column
        vector<vector<int>> result;
        
        // If no nodes, return empty
        if (nodes.empty()) return result;
        
        // Get the first column
        int currentCol = get<0>(nodes[0]);
        vector<int> currentGroup;
        
        for (auto& node : nodes) {
            int col = get<0>(node);
            int val = get<2>(node);
            
            if (col == currentCol) {
                // Same column - add to this group
                currentGroup.push_back(val);
            } else {
                // New column - save previous group
                result.push_back(currentGroup);
                
                // Start new group
                currentGroup.clear();
                currentGroup.push_back(val);
                currentCol = col;
            }
        }
        
        // Add the last group
        if (!currentGroup.empty()) {
            result.push_back(currentGroup);
        }
        
        return result;
    }
    
    // Helper function to collect nodes with coordinates
    void collectNodes(TreeNode* root, int col, int row, 
                      vector<tuple<int, int, int>>& nodes) {
        if (root == nullptr) return;
        
        // Save this node: (column, row, value)
        nodes.push_back({col, row, root->val});
        
        // Go left: column decreases, row increases
        collectNodes(root->left, col - 1, row + 1, nodes);
        
        // Go right: column increases, row increases
        collectNodes(root->right, col + 1, row + 1, nodes);
    }
};