
class Solution {
public:

    void inorder(TreeNode* node,int k,int& count,int& answer)
    {
        if(!node) return;

        inorder(node->left,k,count,answer);

        count++;
        if(count==k)
        {
            answer=node->val;
            return;
        }

        inorder(node->right,k,count,answer);
    }




    int kthSmallest(TreeNode* root, int k) {
        int count=0;
        int answer=-1;

        inorder(root,k,count,answer);
        return answer;
    }
};