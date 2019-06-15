/*
Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.

Note: The length of path between two nodes is represented by the number of edges between them.

Example 1:

Input:

              5
             / \
            4   5
           / \   \
          1   1   5
Output:

2
Example 2:

Input:

              1
             / \
            4   5
           / \   \
          4   4   5
Output:

2
Note: The given binary tree has not more than 10000 nodes. The height of the tree is not more than 1000.
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
    int longestUnivaluePath(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return (res > 0 ? res-1 : 0);
    }
    
    int dfs(TreeNode* root, int& res) {
        if (!root) return 0;
        
        int left_path = dfs(root->left, res);
        int right_path = dfs(root->right, res);
        
        int max_len = 1;
        if (root->left != NULL && root->left->val == root->val) max_len += left_path;
        if (root->right != NULL && root->right->val == root->val) max_len += right_path;
        res = max(max_len, res);
        
        max_len = 1;
        if (root->left != NULL && root->left->val == root->val) max_len = max(max_len, left_path+1);
        if (root->right != NULL && root->right->val == root->val) max_len = max(max_len, right_path+1);
        return max_len;
    }
};

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    
    int longest = 0;
    public int longestUnivaluePath(TreeNode root) {
        dfs(root);
        return longest == 0 ? 0 : longest - 1;
    }
    
    // only several cases to update the length
    private int dfs(TreeNode root) {
        if (root == null) return 0;
        int left = dfs(root.left);
        int right = dfs(root.right);
        
        int longestLength = 1, returnLength = 1;
        if (root.right != null && root.right.val == root.val) {
            longestLength += right;
            returnLength = right + 1;
        }
        if (root.left != null && root.left.val == root.val) {
            longestLength += left;
            returnLength = Math.max(left + 1, returnLength);
        }
        longest = Math.max(longestLength, longest);
        return returnLength;
    }
}
