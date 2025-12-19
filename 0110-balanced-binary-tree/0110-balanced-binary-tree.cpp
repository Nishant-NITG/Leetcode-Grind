class Solution {
public:
    
    int height(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int left = height(root->left);
        if (left == -1) return -1;   // left subtree unbalanced

        int right = height(root->right);
        if (right == -1) return -1;  // right subtree unbalanced

        if (abs(left - right) > 1)
            return -1;               // current node unbalanced

        return 1 + max(left, right); // balanced → return height
    }

    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};
