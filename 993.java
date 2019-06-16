
/*
In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.


*/

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
    public boolean isCousins(TreeNode root, int x, int y) {
        return find(root, x, y, 0) == -2;
    }
    
    // -1 means couldn't find that
    // return the level of node x or y
    // the lca is found, return level_x == level_y? 
    private int find(TreeNode root, int x, int y, int level) {
        if (root == null) return -1;
        if (root.val == x || root.val == y) return level;
        int left = find(root.left, x, y, level+1);
        int right = find(root.right, x, y, level+1);
        if (left != -1 && right != -1) {
            if (left == right && root.left.val != x && root.left.val != y) return -2;
            return -3;
        }
        if (left != -1) return left;
        else return right;
    }
}
