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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode *> q;
        TreeNode *p;
        bool asc = true;
        
        if (root == NULL) return res;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            vector<int> v;
            while (size--) {
                p = q.front();
                q.pop();
                v.push_back(p->val);
                
                if (p->left != NULL) q.push(p->left);
                if (p->right != NULL) q.push(p->right);
            }
            if (!asc) reverse(v.begin(), v.end());
            res.push_back(v);
            asc = !asc;
        }
        return res;
    }
};
