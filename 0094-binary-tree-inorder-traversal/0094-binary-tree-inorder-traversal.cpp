
class Solution {
public:

    void trav(TreeNode* root,vector<int>&ans)
    {
        if(!root) return;
        trav(root->left,ans);
        ans.push_back(root->val);
        trav(root->right, ans);
    }



    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        trav(root,ans);
        return ans;

    }
};