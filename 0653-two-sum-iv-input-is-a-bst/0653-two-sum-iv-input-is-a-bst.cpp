
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& v) {
        if (!root) return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }


    bool findTarget(TreeNode* root, int k) {
        vector<int>v;
        inorder(root,v);

        int i=0,j=v.size()-1;

        while(i<j)
        {
            int sum=v[i]+v[j];

            if(sum==k) return true;
            else if(sum<k) i++;
            else j--;
        }
        return false;
    }
};