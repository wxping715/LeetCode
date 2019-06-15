/*
Given a binary tree rooted at root, the depth of each node is the shortest distance to the root.

A node is deepest if it has the largest depth possible among any node in the entire tree.

The subtree of a node is that node, plus the set of all descendants of that node.

Return the node with the largest depth such that it contains all the deepest nodes in its subtree.

 

Example 1:

Input: [3,5,1,6,2,0,8,null,null,7,4]
Output: [2,7,4]
Explanation:
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
    public TreeNode subtreeWithAllDeepest(TreeNode root) {
        Pair pair = search(root);
        return pair.node;
    }
    
    Pair search(TreeNode root) {
        if (root == null) return new Pair(null, 0);
        Pair left = search(root.left);
        Pair right = search(root.right);
        
        if ((left.length == right.length))
            return new Pair(root, left.length + 1);
        else if (left.length > right.length)
            return new Pair(left.node, left.length+1);
        else
            return new Pair(right.node, right.length+1);
    }
    
    private class Pair  {
        TreeNode node;
        int length;
        
        public Pair(TreeNode node, int length) {
            this.node = node;
            this.length = length;
        }
    }
}
