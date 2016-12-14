/*Given a binary tree, collect a tree's nodes as if you were doing this: Collect and remove all leaves, repeat until the tree is empty.

Example:
Given binary tree 
          1
         / \
        2   3
       / \     
      4   5    
Returns [4, 5, 3], [2], [1].

Explanation:
1. Removing the leaves [4, 5, 3] would result in this tree:

          1
         / 
        2          
2. Now removing the leaf [2] would result in this tree:

          1          
3. Now removing the leaf [1] would result in the empty tree:

          []         
Returns [4, 5, 3], [2], [1].

Credits:
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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) return res;
        
        unordered_map<TreeNode*, int> smap;
        depth(smap, root);
        
        int h = smap[root];
        res.resize(h);
        path(root, res, smap);
        return res;
    }
    
    int depth(unordered_map<TreeNode*, int>& smap, TreeNode *root) {
        int d;
        if (root->left == NULL && root->right == NULL) d = 1;
        else if (root->left == NULL) d = depth(smap, root->right)+1;
        else if (root->right == NULL) d = depth(smap, root->left)+1;
        else d = max(depth(smap, root->left), depth(smap, root->right))+1;

        smap[root] = d;
        return d;
    }
    
    void path(TreeNode *root, vector<vector<int>>& res, unordered_map<TreeNode*, int>& smap) {
        // cout << root->val << endl;
        int h = smap[root];
        res[h-1].push_back(root->val);
        
        if (root->left != NULL) path(root->left, res, smap);
        if (root->right != NULL) path(root->right, res, smap);
    }
};
