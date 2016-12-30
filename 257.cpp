/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    // dfs
    // vector<string> binaryTreePaths(TreeNode* root) {
    //     vector<string> ret, path;
    //     if (!root) return ret;
    //     generate(root, path, ret);
    //     return ret;
    // }
    
    // void generate(TreeNode* root, vector<string>& path, vector<string>& ret) {
    //     path.push_back(to_string(root->val));
    //     if (!root->left && !root->right) {
    //         string pstr = "";
    //         for (int i = 0; i < path.size(); i++) {
    //             if (i != 0) pstr += "->";
    //             pstr += path[i];
    //         }
    //         ret.push_back(pstr);
    //     }
        
    //     if (root->left) generate(root->left, path, ret);
    //     if (root->right) generate(root->right, path, ret);
    //     path.pop_back();
    // }
    
    //iterival
    vector<string> binaryTreePaths(TreeNode* root) {
        stack<TreeNode*> s;
        stack<string> path;
        vector<string> ret;
        if (!root) return ret;
        
        s.push(root);
        path.push("");
        while (!s.empty()) {
            auto cur = s.top(); s.pop();
            string cpath = path.top(); path.pop();
            if (!cur->left && !cur->right) ret.push_back(cpath+to_string(cur->val));
            if (cur->right) {
                s.push(cur->right);
                path.push(cpath+to_string(cur->val)+"->");
            }
            if (cur->left) {
                s.push(cur->left);
                path.push(cpath+to_string(cur->val)+"->");
            }
        }
        return ret;
     }
};
