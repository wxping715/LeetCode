/*
Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
For example:
Given BST [1,null,2,2],
   1
    \
     2
    /
   2
return [2].

Note: If a tree has more than one mode, you can return them in any order.

Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).
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
    /*
    * O(N) time, O(1) space
    */
    vector<int> findMode(TreeNode* root) {
        int maxf = 0, pre = INT_MIN, cnt = 0;
        vector<int> res;
        
        inorder(root, maxf, pre, cnt);
        pre = INT_MIN, cnt = 0;
        getMode(root, maxf, pre, cnt, res);
        return res;
    }
    
    void getMode(TreeNode* root, int maxf, int& pre, int& cnt, vector<int>& res) {
        if (!root) return;
        getMode(root->left, maxf, pre, cnt, res);
        
        cnt = (pre == root->val ? cnt+1 : 1);
        pre = root->val;
        if (maxf == cnt) res.push_back(root->val);
        
        getMode(root->right, maxf, pre, cnt, res);
    }
    
    void inorder(TreeNode* root, int& maxf, int& pre, int& cnt) {
        if (!root) return;
        
        inorder(root->left, maxf, pre, cnt);
        
        cnt = (pre == root->val ? cnt+1 : 1);
        maxf = max(maxf, cnt);
        pre = root->val;
        
        inorder(root->right, maxf, pre, cnt);
    }
};
