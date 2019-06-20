/*
// Definition for a Node.
class Node {
    public int val;
    public Node prev;
    public Node next;
    public Node child;

    public Node() {}

    public Node(int _val,Node _prev,Node _next,Node _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
    public Node flatten(Node head) {
        Stack<Node> stack = new Stack();
        Node p = head;
        Node pre = null;
        while (p != null || !stack.empty()) {
            while (p != null) {
                stack.push(p);
                p.prev = pre;
                if (pre != null) pre.child = p;
                pre = p;
                p = p.child;
            }
            
            p = stack.pop();
            p = p.next;
        }
        
        p = head;
        while (p != null) {
            p.next = p.child;
            p.child = null;
            p = p.next;
        }
        return head;
    }
}
