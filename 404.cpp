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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        dfs(root, sum);
        return sum;
    }
    
    void dfs(TreeNode* root, int& sum) {
        if (!root || (!root->left && !root->right)) return;
        if (root->left && (!root->left->left && !root->left->right)) {
            sum += root->left->val;
        }
        
        if (root->left) dfs(root->left, sum);
        if (root->right) dfs(root->right, sum);
    }
};
