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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (checkSubtree(s, t)) return true;
        if (s->left && isSubtree(s->left, t)) return true;
        if (s->right && isSubtree(s->right, t)) return true;
        return false;
    }
    
    bool checkSubtree(TreeNode* s, TreeNode* t) {
        if (!s && !t) return true;
        if (s && t) {
            return s->val == t->val && checkSubtree(s->left, t->left) && checkSubtree(s->right, t->right);
        }
        return false;
    } 
};
