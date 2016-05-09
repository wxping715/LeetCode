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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode *> q;
        TreeNode *p;
        
        if (root == NULL) return res;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> v;
            while (size--) {
                p = q.front();
                q.pop();
                v.push_back(p->val);
                
                if (p->left != NULL) q.push(p->left);
                if (p->right != NULL) q.push(p->right);
            }
            res.push_back(v);
        }
        return res;
    }
};
