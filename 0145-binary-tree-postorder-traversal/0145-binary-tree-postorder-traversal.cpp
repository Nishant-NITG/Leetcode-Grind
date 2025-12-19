class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {

        vector<int>post;

        stack<TreeNode*>s;
        TreeNode* curr=root;
        TreeNode* lastvisited=nullptr;

        while(!s.empty() || curr!=nullptr)
        {
            if(curr!=nullptr)
            {
                s.push(curr);
                curr=curr->left;
            }

            else
            {
                TreeNode* node=s.top();

                if(node->right!=nullptr && lastvisited!=node->right)
                {
                    curr=node->right;
                }
                else
                {
                    post.push_back(node->val);
                    lastvisited=node;
                    s.pop();
                }
            }
        }

        return post;
    }
};
