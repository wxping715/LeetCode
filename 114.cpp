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
    void flatten(TreeNode* root) {
        stack<TreeNode*> s;
        if (!root) return;
        s.push(root);
        
        TreeNode* rear = NULL;
        while (!s.empty()) {
            TreeNode* cur = s.top();
            s.pop();
            if (cur->right) s.push(cur->right);
            if (cur->left) s.push(cur->left);
            
            cur->left = NULL;
            cur->right = NULL;
            if (rear) rear->right = cur;
            rear = cur;
        }
    }
};
