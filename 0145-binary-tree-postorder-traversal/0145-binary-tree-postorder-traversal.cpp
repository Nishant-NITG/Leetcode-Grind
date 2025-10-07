
class Solution {
public:

    void trav(TreeNode* root,vector<int>&ans)
    {
        if(!root) return;
        trav(root->left, ans);    
        trav(root->right, ans);  
        ans.push_back(root->val); 
    }




    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        trav(root, ans);
        return ans;
    }
};