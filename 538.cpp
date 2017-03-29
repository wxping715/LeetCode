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
    TreeNode* convertBST(TreeNode* root) {
        int gsum = 0;
        dfs(root, gsum);
        return root;
    }
    
    void dfs(TreeNode* &root, int& gsum) {
        if (root == NULL) return;
        dfs(root->right, gsum);
        root->val += gsum;
        gsum = root->val;
        dfs(root->left, gsum);
    }
};
