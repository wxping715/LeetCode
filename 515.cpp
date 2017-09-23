/*
You need to find the largest value in each row of a binary tree.

Example:
Input: 

          1
         / \
        3   2
       / \   \  
      5   3   9 

Output: [1, 3, 9]
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        if (!root) return res;
        q.push(root);
        while (!q.empty()) {
            int n = q.size(), maxv = q.front()->val;
            while (n--) {
                TreeNode* top = q.front();
                q.pop();
                maxv = max(maxv, top->val);
                if (top->left) q.push(top->left);
                if (top->right) q.push(top->right);
            }
            res.push_back(maxv);
        }
        return res;
    }
};
