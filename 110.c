/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
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
    bool isBalanced(TreeNode* root) {
        int r = height(root);
        return r != -1;
    }
    
    int height(TreeNode* root) {
        if (!root) return 0;
        
        int l = height(root->left);
        int r = height(root->right);
        
        if (l == -1 || r == -1 || abs(l-r) > 1)
            return -1;
        return max(l,r)+1;
    }
};
