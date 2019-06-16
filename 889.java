/*
Return any binary tree that matches the given preorder and postorder traversals.

Values in the traversals pre and post are distinct positive integers.

 

Example 1:

Input: pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
Output: [1,2,3,4,5,6,7]
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
    public TreeNode constructFromPrePost(int[] pre, int[] post) {
        if (pre == null || post == null || pre.length == 0 || post.length == 0) return null;
        return construct(pre, post, 0, pre.length-1, 0, post.length-1);
    }
    
    private TreeNode construct(int pre[], int[] post, int preLeft, int preRight, int postLeft, int postRight) {
        if (preLeft > preRight) return null;
        
        TreeNode root = new TreeNode(pre[preLeft]);
        Set<Integer> preSet = new HashSet<>();
        Set<Integer> postSet = new HashSet<>();
        for (int leftCount = 1; leftCount <= preRight - preLeft; leftCount++) {
            preSet.add(pre[preLeft + leftCount]);
            postSet.add(post[postLeft + leftCount - 1]);
            if (preSet.containsAll(postSet)) {
                // (preLeft+1, preLeft+leftCount) -> leftTree
                // (preLeft+leftCount+1, preRight) -> rightTree
                root.left = construct(pre, post, preLeft+1, preLeft+leftCount, postLeft, postLeft+leftCount-1);
                root.right = construct(pre, post, preLeft+leftCount+1, preRight, postLeft+leftCount, postRight-1);
                return root;
            }
        }
        return root;
    }
}
