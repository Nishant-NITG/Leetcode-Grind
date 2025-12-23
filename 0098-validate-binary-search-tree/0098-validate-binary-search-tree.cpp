
class Solution {
public:

    bool helper(TreeNode* root,long mini,long maxi)
    {
        if(root==nullptr)
        return true;

        if(root->val<=mini || root->val>=maxi)
        {
            return false;
        }

        return helper(root->left,mini,root->val) && helper(root->right,root->val,maxi);
    }



    bool isValidBST(TreeNode* root) {
        return helper(root,LONG_MIN,LONG_MAX);
    }
};