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
    
    // O(1) solution
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> results = new ArrayList<>();
        dfs(root, 0, results);
        return results;
    }
    
    private void dfs(TreeNode root, int level, List<Integer> results) {
        if (root == null) return;
        if (level == results.size())
            results.add(root.val);
        dfs(root.right, level+1, results);
        dfs(root.left, level+1, results);
    }
}
