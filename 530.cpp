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
    int getMinimumDifference(TreeNode* root) {
        int mindiff = INT_MAX;
        TreeNode* pre = NULL;
        inorder(root, pre, mindiff);
        return mindiff;
    }
    
    void inorder(TreeNode* root, TreeNode* &pre, int& mindiff) {
        if (!root) return;
        
        inorder(root->left, pre, mindiff);
        if (pre) mindiff = min(mindiff, abs(pre->val - root->val));
        pre = root;
        inorder(root->right, pre, mindiff);
    }
};
