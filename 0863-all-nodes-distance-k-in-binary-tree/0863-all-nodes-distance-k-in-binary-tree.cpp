class Solution {
private:
    unordered_map<TreeNode*, TreeNode*> parent;
    
    // Build parent pointers using DFS
    void buildParent(TreeNode* node, TreeNode* par) {
        if (!node) return;
        parent[node] = par;
        buildParent(node->left, node);
        buildParent(node->right, node);
    }
    
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // Step 1: Build parent pointers
        buildParent(root, nullptr);
        
        // Step 2: BFS from target
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        q.push(target);
        visited.insert(target);
        
        int distance = 0;
        
        while (!q.empty()) {
            // If we've reached the desired distance, break
            if (distance == k) break;
            
            int levelSize = q.size();
            
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                // Check left child
                if (node->left && !visited.count(node->left)) {
                    q.push(node->left);
                    visited.insert(node->left);
                }
                
                // Check right child
                if (node->right && !visited.count(node->right)) {
                    q.push(node->right);
                    visited.insert(node->right);
                }
                
                // Check parent (this is what makes it a graph!)
                if (parent[node] && !visited.count(parent[node])) {
                    q.push(parent[node]);
                    visited.insert(parent[node]);
                }
            }
            distance++;
        }
        
        // Step 3: Collect all nodes at distance k
        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front()->val);
            q.pop();
        }
        
        return result;
    }
};