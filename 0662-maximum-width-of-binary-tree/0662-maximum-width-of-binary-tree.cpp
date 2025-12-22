
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==nullptr)
        {
            return 0;
        }

        long long ans=0;

        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});

        while(!q.empty())
        {
            int size=q.size();
            long long firstIndex=q.front().second;
            long long lastIndex=q.back().second;

            ans=max(ans,lastIndex-firstIndex+1);

            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front().first;
                long long index=q.front().second-firstIndex;
                q.pop();

                if(node->left!=nullptr)
                {
                    q.push({node->left,2*index+1});
                }

                if(node->right!=NULL)
                {
                    q.push({node->right,2*index+2});
                }

            }
        }

        return ans;
    }
};