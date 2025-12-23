class Solution {
public:
    TreeNode* first = nullptr;
    TreeNode* middle = nullptr;
    TreeNode* last = nullptr;
    TreeNode* prev = nullptr;

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        if (prev && prev->val > root->val) {
            if (!first) {
                first = prev;
                middle = root;
            } else {
                last = root;
            }
        }

        prev = root;

        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);

        if (first && last)
            swap(first->val, last->val);
        else if (first && middle)
            swap(first->val, middle->val);
    }
};
