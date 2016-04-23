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

    /*
    * dp problem based tree, must use the cache
    * dp(node, 1) means the maximum value if rob node, dp(node, 0) means the maximum value if not rob the node
    *       1. dp(node, 1) = dp(root->left, 0) + dp(root->right, 0) + root->val
    *       2. dp(node, 0) = max(dp(root->left, 0), dp(root->left, 1)) + max(dp(root->right, 0), dp(root->right, 1))
    */
    map<pair<TreeNode*, bool>, int> calced;
    
    int rob(TreeNode* root) {
        return max(dp(root, true), dp(root, false));
    }
    
    int dp(TreeNode* root, bool flag) {
        if (root == NULL) return 0;
        
        map<pair<TreeNode*, bool>, int>::iterator it;
        it = calced.find(make_pair(root, flag));
        if (it != calced.end()) return it->second;
        
        int res;
        if (flag) res = dp(root->left, false) + dp(root->right, false) + root->val;
        else res = max(dp(root->left, false), dp(root->left, true)) + max(dp(root->right, false), dp(root->right, true));
        calced[make_pair(root, flag)] = res;
        return res;
    }
};
