/*
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return generate(1, n);
    }
    
    vector<TreeNode*> generate(int l, int r) {
        if (l > r) return {NULL};
        vector<TreeNode*> res;
        for (int m = l; m <= r; m++) {
            vector<TreeNode*> left = generate(l, m-1);
            vector<TreeNode*> right = generate(m+1, r);
            
            for (TreeNode* lnode : left)
                for (TreeNode* rnode : right) {
                    TreeNode* root = new TreeNode(m);
                    root->left = lnode;
                    root->right = rnode;
                    res.push_back(root);
                }
        }
        return res;
    }
};
