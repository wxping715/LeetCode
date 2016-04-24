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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;
        
        TreeNode* cur = root, *sm, *la;
        if (p->val > q->val) {
            sm = q;
            la = p;
        } else {
            sm = p;
            la = q;
        }
        while (cur != NULL) {
            if (sm->val <= cur->val && la->val >= cur->val) return cur;
            else if(sm->val < cur->val && la->val < cur->val) cur = cur->left;
            else cur = cur->right;
        }
        return NULL;
    }
};
