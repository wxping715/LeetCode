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
    int diameterOfBinaryTree(TreeNode* root) {
        int maxl = root ? 1 : 0;
        dfs(root, maxl);
        return max(maxl-1,0);
    }
    
    int dfs(TreeNode* root, int& maxl) {
        if (root == NULL) return 0;
        if (!root->left && !root->right) return 1;
        
        int llen = dfs(root->left, maxl), rlen = dfs(root->right, maxl);
        int len = llen + rlen +1;
        maxl = max(maxl, len);
        return max(llen, rlen)+1;
    }
};
