/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:
    2
   / \
  1   3
Binary tree [2,1,3], return true.
Example 2:
    1
   / \
  2   3
Binary tree [1,2,3], return false.
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
    
    // recursive, lower and upper
//     bool isValidBST(TreeNode* root) {
//         return detect(root, LONG_MIN, LONG_MAX);
//     }
    
//     bool detect(TreeNode* root, long down, long up) {
//         if (!root) return true;
        
//         if (root->val <= down || root->val >= up) return false;
//         if (!detect(root->left, down, root->val)) return false;
//         return detect(root->right, root->val, up);
//     }
    
    // recursive, pre
    TreeNode* pre = NULL;
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        
        if (!isValidBST(root->left))
            return false;
        if (pre && pre->val >= root->val)
            return false;
        pre = root;
        return isValidBST(root->right);
    }
};
