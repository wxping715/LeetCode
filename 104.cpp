/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/


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
    int maxDepth(TreeNode* root) {
        int res = 0;
        dfs(root, 0, res);
        
        return res;
    }
    
    void dfs(TreeNode* root, int d, int& res) {
        if (!root) {
            res = max(res, d);
            return;
        }
        
        dfs(root->left, d+1, res);
        dfs(root->right, d+1, res);
    }
};
