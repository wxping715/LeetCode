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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode *> q;
        TreeNode* cur;
        
        q.push(root);
        while (!q.empty()) {
            cur = q.front();
            q.pop();
            if (cur->right) q.push(cur->right);
            if (cur->left) q.push(cur->left);
        }
        return cur->val;
    }
};
