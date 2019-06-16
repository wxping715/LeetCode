/*
Given the root of a binary tree, each node has a value from 0 to 25 representing the letters 'a' to 'z': a value of 0 represents 'a', a value of 1 represents 'b', and so on.

Find the lexicographically smallest string that starts at a leaf of this tree and ends at the root.

(As a reminder, any shorter prefix of a string is lexicographically smaller: for example, "ab" is lexicographically smaller than "aba".  A leaf of a node is a node that has no children.)
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
    public String smallestFromLeaf(TreeNode root) {
        String suffix = "";
        return construct(root, suffix);
    }
    
    private String construct(TreeNode root, String suffix) {
        if (root == null) return suffix;
        suffix = String.valueOf((char)(root.val + 'a')) + suffix;
        
        String left = construct(root.left, suffix);
        String right = construct(root.right, suffix);
        
        String smaller;
        if (root.left == null) smaller = right;
        else if (root.right == null) smaller = left;
        else smaller = left.compareTo(right) < 0 ? left : right;
        return smaller;
    }
}
