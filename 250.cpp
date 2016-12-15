/*Given a binary tree, count the number of uni-value subtrees.

A Uni-value subtree means all nodes of the subtree have the same value.

For example:
Given binary tree,
              5
             / \
            1   5
           / \   \
          5   5   5
return 4.*/


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
    int countUnivalSubtrees(TreeNode* root) {
        int sum = 0;
        if (root == NULL) return sum;
        dfs(root, sum);
        return sum;
    }
    
    bool dfs(TreeNode* root, int& sum) {
        // cout << root->val << endl;
        if ((!root->left && !root->right) || 
            (root->left && !root->right && dfs(root->left, sum) && root->val == root->left->val) || 
            (!root->left && root->right && dfs(root->right, sum) && root->val == root->right->val)) {
                sum += 1;
                return true;
            }
        else if (root->left && root->right) {
            bool lres = dfs(root->left, sum);
            bool rres = dfs(root->right, sum);
            if (lres && rres && root->val == root->left->val && root->val == root->right->val) {
                sum += 1;
                return true;
            }
        }
        return false;
    }
};
