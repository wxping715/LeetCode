/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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
    int minDepth(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        if (!root) return 0;
        q.emplace(root, 1);
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            
            if (!cur.first->left && !cur.first->right)
                return cur.second;
            
            if (cur.first->left)
                q.emplace(cur.first->left, cur.second+1);
            if (cur.first->right)
                q.emplace(cur.first->right, cur.second+1);
        }
    }
};
