class Solution {
public:
    unordered_map<int, int> indexMap;
    int postIndex;

    TreeNode* build(vector<int>& inorder, vector<int>& postorder,
                    int inStart, int inEnd) {

        // base case
        if (inStart > inEnd)
            return NULL;

        // pick root from postorder (last element)
        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        // find root position in inorder
        int pos = indexMap[rootVal];

        // IMPORTANT:
        // build RIGHT subtree first
        root->right = build(inorder, postorder, pos + 1, inEnd);
        root->left  = build(inorder, postorder, inStart, pos - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        // build index map
        for (int i = 0; i < inorder.size(); i++) {
            indexMap[inorder[i]] = i;
        }

        // start from last index of postorder
        postIndex = postorder.size() - 1;

        return build(inorder, postorder, 0, inorder.size() - 1);
    }
};
