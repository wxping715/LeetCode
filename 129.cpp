/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
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
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        vector<int> path;
        dfs(root, path, sum);
        return sum;
    }
    
    void dfs(TreeNode* root, vector<int>& path, int& sum) {
        if (!root) return;
        
        path.push_back(root->val);
        if (!root->left && !root->right) {
            sum += num(path);
        }
        dfs(root->left, path, sum);
        dfs(root->right, path, sum);
        path.pop_back();
    }
    
    int num(vector<int>& path) {
        int r = 0;
        for (int n : path)
            r = r*10 + n;
        return r;
    }
};
