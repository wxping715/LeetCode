/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]

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
