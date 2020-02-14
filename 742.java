/*
742. Closest Leaf in a Binary Tree
Medium

372

82

Add to List

Share
Given a binary tree where every node has a unique value, and a target key k, find the value of the nearest leaf node to target k in the tree.

Here, nearest to a leaf means the least number of edges travelled on the binary tree to reach any leaf of the tree. Also, a node is called a leaf if it has no children.

In the following examples, the input tree is represented in flattened form row by row. The actual root tree given will be a TreeNode object.

Example 1:

Input:
root = [1, 3, 2], k = 1
Diagram of binary tree:
          1
         / \
        3   2

Output: 2 (or 3)

Explanation: Either 2 or 3 is the nearest leaf node to the target of 1.
Example 2:

Input:
root = [1], k = 1
Output: 1

Explanation: The nearest leaf node is the root node itself.
Example 3:

Input:
root = [1,2,3,4,null,null,null,5,null,6], k = 2
Diagram of binary tree:
             1
            / \
           2   3
          /
         4
        /
       5
      /
     6

Output: 3
Explanation: The leaf node with value 3 (and not the leaf node with value 6) is nearest to the node with value 2.
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
    public int findClosestLeaf(TreeNode root, int k) {
        Map<TreeNode, TreeNode> backMap = new HashMap<>();
        TreeNode kNode = dfs(root, null, k, backMap);
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(kNode);
        Set<TreeNode> hashset = new HashSet<TreeNode>();
        hashset.add(kNode);
        while (!queue.isEmpty()) {
            TreeNode poll = queue.poll();
            if (poll.left == null && poll.right == null)
                return poll.val;
            if (poll.left != null && !hashset.contains(poll.left)) {
                hashset.add(poll.left);
                queue.offer(poll.left);
            }
            if (poll.right != null && !hashset.contains(poll.right)) {
                hashset.add(poll.right);
                queue.offer(poll.right);
            }
            if (backMap.get(poll) != null && !hashset.contains(backMap.get(poll))) {
                hashset.add(backMap.get(poll));
                queue.offer(backMap.get(poll));
            }
        }
        return -1;
    }
    
    TreeNode dfs(TreeNode root, TreeNode prev, int k, Map<TreeNode, TreeNode> backMap) {
        if (root == null) return null;
        backMap.put(root, prev);
        if (root.val == k)
            return root;
        TreeNode left = dfs(root.left, root, k, backMap);
        if (left != null)
            return left;
        return dfs(root.right, root, k, backMap);
    }
}
