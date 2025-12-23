
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr=root;

        while(curr!=nullptr)
        {
            if(curr->left!=nullptr)
            {
                TreeNode* rightmostInLeft=curr->left;
                while(rightmostInLeft->right!=NULL)
                {
                    rightmostInLeft=rightmostInLeft->right;
                }

                rightmostInLeft->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;
            }
            curr=curr->right;
        }

         
    }
};