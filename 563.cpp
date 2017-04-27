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
    int findTilt(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }
    
    int dfs(TreeNode* root, int& res) {
        if (!root) return 0;
        if (!root->left && !root->right) return root->val;
        
        int lsum = dfs(root->left, res);
        int rsum = dfs(root->right, res);
        res += abs(lsum-rsum);
        return root->val + lsum + rsum;
    }
};
