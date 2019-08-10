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
    int ans = 0;
    public int maxPathSum(TreeNode root) {
        ans = Integer.MIN_VALUE;
        dfs(root);
        return ans;
    }
    
    int dfs(TreeNode root) {
        if (root == null) return 0;
        int maxSum = root.val;
        int left = dfs(root.left);
        int right = dfs(root.right);
        maxSum += Math.max(left, right) > 0 ? Math.max(left, right) : 0;
        int maxPath = Math.max(maxSum, root.val + left + right);
        ans = Math.max(ans, maxPath);
        return maxSum;
    }
}
