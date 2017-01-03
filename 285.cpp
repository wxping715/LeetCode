/*Given a binary search tree and a node in it, find the in-order successor of that node in the BST.

Note: If the given node has no in-order successor in the tree, return null. 
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
    // TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    //     if (root == NULL)
    //         return NULL;
    //     if (root->val <= p->val)
    //         return inorderSuccessor(root->right, p);
    //     else {
    //         TreeNode *res = inorderSuccessor(root->left, p);
    //         return res == NULL ? root : res;
    //     }
    // }
    
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* succ = NULL, *cur = root;
        while (cur) {
            if (p->val < cur->val) {
                succ = cur;
                cur = cur->left;
            } else 
                cur = cur->right;
        }
        return succ;
    }
};
