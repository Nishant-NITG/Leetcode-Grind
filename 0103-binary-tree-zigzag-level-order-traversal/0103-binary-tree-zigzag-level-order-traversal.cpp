
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};

        vector<vector<int>>result;
        queue<TreeNode*>q;
        q.push(root);
        bool ltor=true;

        while(!q.empty())
        {
            int levelsize=q.size();
            vector<int>level;

            for(int i=0;i<levelsize;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                level.push_back(node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(!ltor){
                reverse(level.begin(),level.end());
            }
            result.push_back(level);

            ltor=!ltor;
        }
        return result;
    }
};