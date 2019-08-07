/*
// Definition for a Node.
class Node {
    public int val;
    public Node next;
    public Node random;

    public Node() {}

    public Node(int _val,Node _next,Node _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
    public Node copyRandomList(Node head) {
        // A->A'->B->B'
        Node p = head;
        while (p != null) {
            Node copy = new Node(p.val, p.next, null);
            Node temp = p.next;
            p.next = copy;
            p = temp;
        }
        
        // connect
        p = head;
        while (p != null) {
            if (p.random != null) {
                p.next.random = p.random.next;
            }
            p = p.next.next;
        }
        
        print(head);
        
        Node nhead = null, tail = null;
        p = head;
        while (p != null) {
            if (nhead == null) nhead = p.next;
            else tail.next = p.next;
            tail = p.next;
            
            p.next = p.next.next;
            p = p.next;
        }
        
        return nhead;
    }
    
    private void print(Node head) {
        Node p = head;
        while (p != null) {
            System.out.print(p.val + ",");
            // if (p.random != null) System.out.println(p.random.val);
            p = p.next;
        }
    }
}
