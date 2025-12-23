class Solution {
public:
    int idx = 0;

    TreeNode* build(vector<int>& preorder, int upperBound) {
        
        if (idx == preorder.size() || preorder[idx] > upperBound)
            return NULL;


        TreeNode* root = new TreeNode(preorder[idx++]);

       
        root->left = build(preorder, root->val);

   
        root->right = build(preorder, upperBound);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder, INT_MAX);
    }
};
