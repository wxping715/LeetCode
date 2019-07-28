/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;

    public Node() {}

    public Node(int _val,Node _left,Node _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
    public Node treeToDoublyList(Node root) {
        Deque<Node> stack = new LinkedList<>();
        Node head = null, tail = null, pre = null;
        Node p = root;
        while (p != null || !stack.isEmpty()) {
            while (p != null) {
                stack.push(p);
                p = p.left;
            }
            
            // access node p
            p = stack.pop();
            if (head == null) head = p;
            tail = p;
            p.left = pre;
            if (pre != null) pre.right = p;
            pre = p;
            p = p.right;
        }
        
        if (head != null) {
            head.left = tail;
            tail.right = head;
        }
        return head;
    }
}
