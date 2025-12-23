class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {

        // Case 1: empty tree
        if (root == NULL)
            return new TreeNode(val);

        TreeNode* curr = root;

        while (true) {

            // Go left
            if (val < curr->val) {
                if (curr->left != NULL)
                    curr = curr->left;
                else {
                    curr->left = new TreeNode(val);
                    break;
                }
            }

            // Go right
            else {
                if (curr->right != NULL)
                    curr = curr->right;
                else {
                    curr->right = new TreeNode(val);
                    break;
                }
            }
        }

        return root;
    }
};
