/*
510. Inorder Successor in BST II
Medium

74

14

Favorite

Share
Given a binary search tree and a node in it, find the in-order successor of that node in the BST.

The successor of a node p is the node with the smallest key greater than p.val.

You will have direct access to the node but not to the root of the tree. Each node will have a reference to its parent node.
*/

/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node parent;
};
*/
class Solution {
    public Node inorderSuccessor(Node x) {
        if (x == null) return null;
        
        // case 1: has right br
        if (x.right != null) {
            Node p = x.right;
            while (p.left != null) p = p.left;
            return p;
        }
        // case 2: go to the parent
        Node p = x;
        while (p.parent != null) {
            if (p.parent.left == p)
                return p.parent;
            p = p.parent;
        }
        return null;
    }
}
