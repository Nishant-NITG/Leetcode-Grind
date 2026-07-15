class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        
        unsigned long long maxWidth = 0;
        
        // Queue stores (node, index)
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        
        while (!q.empty()) {
            int levelSize = q.size();
            
            // Get the leftmost and rightmost indices at this level
            unsigned long long leftMost = q.front().second;
            unsigned long long rightMost = q.back().second;
            
            // Width = rightmost - leftmost + 1
            maxWidth = max(maxWidth, rightMost - leftMost + 1);
            
            // Process all nodes at this level
            for (int i = 0; i < levelSize; i++) {
                auto [node, idx] = q.front();
                q.pop();
                
                // Normalize index to prevent overflow
                // Subtract leftMost to keep numbers small at each level
                unsigned long long normalizedIdx = idx - leftMost;
                
                // Add children with normalized indices
                if (node->left) {
                    q.push({node->left, 2 * normalizedIdx + 1});
                }
                if (node->right) {
                    q.push({node->right, 2 * normalizedIdx + 2});
                }
            }
        }
        
        return maxWidth;
    }
};