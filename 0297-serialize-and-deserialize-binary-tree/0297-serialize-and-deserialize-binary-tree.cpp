class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";

        queue<TreeNode*> q;
        q.push(root);

        string result = "";

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node == NULL) {
                result += "null,";
                continue;
            }

            result += to_string(node->val) + ",";
            q.push(node->left);
            q.push(node->right);
        }

        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0) return NULL;

        stringstream ss(data);
        string token;

        getline(ss, token, ',');
        TreeNode* root = new TreeNode(stoi(token));

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* parent = q.front();
            q.pop();

            // left child
            if (!getline(ss, token, ',')) break;
            if (token != "null") {
                parent->left = new TreeNode(stoi(token));
                q.push(parent->left);
            }

            // right child
            if (!getline(ss, token, ',')) break;
            if (token != "null") {
                parent->right = new TreeNode(stoi(token));
                q.push(parent->right);
            }
        }

        return root;
    }
};
