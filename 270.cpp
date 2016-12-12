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
    int closestValue(TreeNode* root, double target) {
        if (!root) return 0;
        
        int res = root->val;
        TreeNode* p = root;
        while (p) {
            res = abs(res - target) > abs(p->val - target) ? p->val : res;
            if (target > p->val) p = p->right;
            else p = p->left;
        }
        return res;
    }
};
