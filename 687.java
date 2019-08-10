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
        longest = 0;
        getLength(root, -1);
        return longest;
    }
    
    private int getLength(TreeNode root, int val) {
        if (root == null) return 0;
        int left = getLength(root.left, root.val);
        int right = getLength(root.right, root.val);
        longest = Math.max(longest, left+right);
        if (root.val == val) return Math.max(left+1, right+1);
        return 0;
    }
}
