/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str = "";
        buildString(root, str);
        return str;
    }

    void buildString(TreeNode* root, string& str) {
        if (!root) str += "X,";
        else {
            str += to_string(root->val)+",";
            buildString(root->left, str);
            buildString(root->right, str);
        }
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        deque<string> nodes;
        int i = 0;
        string cur = "";
        while (i < data.length()) {
            while (data[i] != ',')
                cur.push_back(data[i++]);
            i++;
            nodes.push_back(cur);
            cur.clear();
        }
        return buildTree(nodes);
    }
    
    TreeNode* buildTree(deque<string>& nodes) {
        string cur = nodes.front();
        nodes.pop_front();
        if (cur == "X") return NULL;
        else {
            TreeNode* node = new TreeNode(stoi(cur));
            node->left = buildTree(nodes);
            node->right = buildTree(nodes);
            return node;
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
