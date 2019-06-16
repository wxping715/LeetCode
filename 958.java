/*
Given a binary tree, determine if it is a complete binary tree.
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
    public boolean isCompleteTree(TreeNode root) {
        if (root == null) return true;
        Queue<TreeNode> queue = new LinkedList();
        queue.offer(root);
        boolean foundUncompletedNode = false;
        while (!queue.isEmpty()) {
            TreeNode peek = queue.poll();
            if (foundUncompletedNode && (peek.left != null || peek.right != null)) return false;
            // allowed cases:
            // 1. left = null, right = null
            // 2. left != null, right != null
            // 3. left != null, right = null
            if (peek.left == null && peek.right != null) return false;
            if (peek.right == null) foundUncompletedNode = true;
            
            if (peek.left != null) queue.offer(peek.left);
            if (peek.right != null) queue.offer(peek.right);
        }
        return true;
    }
}
