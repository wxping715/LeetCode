/*
Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero sub-node. If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes.

Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.

If no such second minimum value exists, output -1 instead.

Example 1:
Input: 
    2
   / \
  2   5
     / \
    5   7

Output: 5
Explanation: The smallest value is 2, the second smallest value is 5.
Example 2:
Input: 
    2
   / \
  2   2

Output: -1
Explanation: The smallest value is 2, but there isn't any second smallest value.
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
    
    // tranverse
    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1;
        int minv = -1, rvalue = root->val;
        
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            
            if (cur->val > rvalue && (minv == -1 || cur->val < minv))
                minv = cur->val;
            
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        return minv;
    }
    
    // optimize
    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1;
        return dfs(root, root->val);
    }
    
    int dfs(TreeNode* root, int rvalue) {
        if (!root) return -1;
        if (root->val != rvalue) return root->val;
        
        int lres = dfs(root->left, rvalue);
        int rres = dfs(root->right, rvalue);
        
        if (lres == -1) return rres;
        if (rres == -1) return lres;
        return min(lres, rres);
    }
};
