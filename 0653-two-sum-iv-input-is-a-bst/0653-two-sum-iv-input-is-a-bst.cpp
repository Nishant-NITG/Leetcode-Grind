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
        void inorder(TreeNode* root, vector<int>& values) {
        if (!root) return;
        inorder(root->left, values);
        values.push_back(root->val);
        inorder(root->right, values);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int>values;
        inorder(root,values);

        int left=0;
        int right=values.size()-1;

        while(left<right)
        {
            int sum=values[left]+values[right];
            if(sum==k)
            {
                return true;
            }
            else if(sum<k)
            {
                left++;
            }
            else 
            {
                right--;
            }
        }
        return false;
    }
};