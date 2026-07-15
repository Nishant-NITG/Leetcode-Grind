class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: reached end or found one of the nodes
        if (!root || root == p || root == q) {
            return root;
        }
        
        // Search in left and right subtrees
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        // If both left and right found nodes, current root is the LCA
        if (left && right) {
            return root;
        }
        
        // Otherwise, return the non-null side
        // If both null, returns null
        return left ? left : right;
    }
};