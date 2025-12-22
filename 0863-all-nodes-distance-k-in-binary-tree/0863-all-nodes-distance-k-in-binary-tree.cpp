class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q;

        // STEP 1: Build parent mapping
        q.push(root);
        parent[root] = NULL;

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr->left != NULL) {
                parent[curr->left] = curr;
                q.push(curr->left);
            }

            if (curr->right != NULL) {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }

        // STEP 2: BFS from target
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> bfs;

        bfs.push(target);
        visited[target] = true;

        int distance = 0;

        while (!bfs.empty()) {

            int size = bfs.size();

            if (distance == k) {
                break;
            }

            for (int i = 0; i < size; i++) {
                TreeNode* node = bfs.front();
                bfs.pop();

                if (node->left != NULL && visited[node->left] == false) {
                    visited[node->left] = true;
                    bfs.push(node->left);
                }

                if (node->right != NULL && visited[node->right] == false) {
                    visited[node->right] = true;
                    bfs.push(node->right);
                }

                if (parent[node] != NULL && visited[parent[node]] == false) {
                    visited[parent[node]] = true;
                    bfs.push(parent[node]);
                }
            }

            distance++;
        }

        // STEP 3: Collect answer
        vector<int> ans;

        while (!bfs.empty()) {
            ans.push_back(bfs.front()->val);
            bfs.pop();
        }

        return ans;
    }
};
