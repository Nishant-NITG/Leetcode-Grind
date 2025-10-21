/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
    int dfs(TreeNode* node,int& maxSum)
    {
        if(!node) return 0;


        int leftMax=max(dfs(node->left,maxSum),0);
        int rightMax=max(dfs(node->right,maxSum),0);
        int pathThroughNode = node->val + leftMax + rightMax;

        maxSum=max(maxSum,pathThroughNode);

        return node->val + max(leftMax,rightMax);

    }


public:
    int maxPathSum(TreeNode* root) {
        int maxSum=INT_MIN;
        dfs(root,maxSum);
        return maxSum;
    }


};