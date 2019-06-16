/*
A full binary tree is a binary tree where each node has exactly 0 or 2 children.

Return a list of all possible full binary trees with N nodes.  Each element of the answer is the root node of one possible tree.

Each node of each tree in the answer must have node.val = 0.

You may return the final list of trees in any order.

 

Example 1:

Input: 7
Output: [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
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
    public List<TreeNode> allPossibleFBT(int N) {
        if (N == 1) {
            TreeNode root = new TreeNode(0);
            root.left = root.right = null;
            return Arrays.asList(root);
        }
        
        List<TreeNode> all = new ArrayList();
        for (int left = 1; left < N; left += 2) {
            List<TreeNode> leftTrees = allPossibleFBT(left);
            List<TreeNode> rightTrees = allPossibleFBT(N - left - 1);
            
            for (TreeNode leftSubTree : leftTrees) {
                for (TreeNode rightSubTree : rightTrees) {
                    TreeNode root = new TreeNode(0);
                    root.left = leftSubTree;
                    root.right = rightSubTree;
                    all.add(root);
                }
            }
        }
        return all;
    }
}
