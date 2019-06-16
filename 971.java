/*
Given a binary tree with N nodes, each node has a different value from {1, ..., N}.

A node in this binary tree can be flipped by swapping the left child and the right child of that node.

Consider the sequence of N values reported by a preorder traversal starting from the root.  Call such a sequence of N values the voyage of the tree.

(Recall that a preorder traversal of a node means we report the current node's value, then preorder-traverse the left child, then preorder-traverse the right child.)

Our goal is to flip the least number of nodes in the tree so that the voyage of the tree matches the voyage we are given.

If we can do so, then return a list of the values of all nodes flipped.  You may return the answer in any order.

If we cannot do so, then return the list [-1].
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
    private List<Integer> flippedNodes = new ArrayList();
    private int index = 0;
    
    public List<Integer> flipMatchVoyage(TreeNode root, int[] voyage) {
        if (root == null && (voyage == null || voyage.length == 0)) return Collections.emptyList();
        if (root == null) return Arrays.asList(-1);
        
        boolean couldFlip = dfs(root, voyage);
        if (!couldFlip) return Arrays.asList(-1);
        return flippedNodes;
    }
    
    // return if the traversal match voyage
    private boolean dfs(TreeNode root, int[] voyage) {
        if (root == null) return true;
        if (root.val != voyage[index]) return false;
        index++;
        int currentIndex = index;
        if (dfs(root.left, voyage) && dfs(root.right, voyage)) return true;
        // flip and reset the index
        index = currentIndex;
        if (dfs(root.right, voyage) && dfs(root.left, voyage)) {
            flippedNodes.add(root.val);
            return true;
        }
        return false;
    }
}
