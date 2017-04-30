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
    void recoverTree(TreeNode* &root) {
        TreeNode* pre = new TreeNode(INT_MIN);
        TreeNode* p1 = search(root, pre, true);
        
        pre = new TreeNode(INT_MAX);
        TreeNode* p2 = search(root, pre, false);
        
        if (!p1 || !p2) return;
        int t = p1->val;
        p1->val = p2->val;
        p2->val = t;
    }
    
    TreeNode* search(TreeNode* root, TreeNode* &pre, bool increament) {
        if (!root) return NULL;
        
        TreeNode* res = search((increament ? root->left : root->right), pre, increament);
        if (res) return res;
        
        if (increament && root->val <= pre->val) return pre;
        if (!increament && root->val >= pre->val) return pre;
        
        pre = root;
        return search((increament? root->right : root->left), pre, increament);
    }
};
