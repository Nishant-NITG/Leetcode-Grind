
class Solution {
public:

    int left(TreeNode* node)
    {
        int height=0;
        while(node!=NULL)
        {
            height++;
            node=node->left;
        }

        return height;
    }

    int right(TreeNode* node)
    {
        int height;
        while(node!=NULL)
        {
            height++;
            node=node->right;
        }

        return height;
    }



    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int l=left(root);
        int r=right(root);

        if(l==r)
        {
            return (1 << l)-1;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};