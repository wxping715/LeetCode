/*
A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.

Write a data structure CBTInserter that is initialized with a complete binary tree and supports the following operations:

CBTInserter(TreeNode root) initializes the data structure on a given tree with head node root;
CBTInserter.insert(int v) will insert a TreeNode into the tree with value node.val = v so that the tree remains complete, and returns the value of the parent of the inserted TreeNode;
CBTInserter.get_root() will return the head node of the tree.
 

Example 1:

Input: inputs = ["CBTInserter","insert","get_root"], inputs = [[[1]],[2],[]]
Output: [null,1,[1,2]]
Example 2:

Input: inputs = ["CBTInserter","insert","insert","get_root"], inputs = [[[1,2,3,4,5,6]],[7],[8],[]]
Output: [null,3,4,[1,2,3,4,5,6,7,8]]
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
class CBTInserter {
    private Queue<TreeNode> uncompleteNodes = new LinkedList();
    private TreeNode root;
    
    public CBTInserter(TreeNode root) {
        if (root == null) return;
        this.root = root;
        traverseTree(root);
    }
    
    public int insert(int v) {
        TreeNode newNode = newNode(v);
        int parent = 0;
        if (root == null) {
            root = newNode;
        } else {
            TreeNode peek = uncompleteNodes.peek();
            if (peek.left == null) peek.left = newNode;
            else {
                uncompleteNodes.poll();
                peek.right = newNode;
            }
            parent = peek.val;
        }
        uncompleteNodes.offer(newNode);
        return parent;
    }
    
    public TreeNode get_root() {
        return root;
    }
    
    private TreeNode newNode(int v) {
        TreeNode newNode = new TreeNode(v);
        newNode.left = newNode.right = null;
        return newNode;
    } 
    
    private void traverseTree(TreeNode root) {
        if (root == null) return;
        Queue<TreeNode> queue = new LinkedList();
        queue.offer(root);
        while (!queue.isEmpty()) {
            TreeNode peek = queue.poll();
            if (peek.left == null || peek.right == null) uncompleteNodes.offer(peek);
            if (peek.left != null) queue.offer(peek.left);
            if (peek.right != null) queue.offer(peek.right);
        }
    }
}

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter obj = new CBTInserter(root);
 * int param_1 = obj.insert(v);
 * TreeNode param_2 = obj.get_root();
 */
