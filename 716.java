/*

716. Max Stack

Design a max stack that supports push, pop, top, peekMax and popMax.

push(x) -- Push element x onto stack.
pop() -- Remove the element on top of the stack and return it.
top() -- Get the element on the top.
peekMax() -- Retrieve the maximum element in the stack.
popMax() -- Retrieve the maximum element in the stack, and remove it. If you find more than one maximum elements, only remove the top-most one.
Example 1:
MaxStack stack = new MaxStack();
stack.push(5); 
stack.push(1);
stack.push(5);
stack.top(); -> 5
stack.popMax(); -> 5
stack.top(); -> 1
stack.peekMax(); -> 5
stack.pop(); -> 1
stack.top(); -> 5
Note:
-1e7 <= x <= 1e7
Number of operations won't exceed 10000.
The last four operations won't be called when stack is empty.
*/

class MaxStack {
    TreeMap<Integer, List<ListNode>> map = new TreeMap<>();
    ListNode stack = new ListNode(Integer.MAX_VALUE, null, null);
    
    /** initialize your data structure here. */
    public MaxStack() {
        
    }
    
    public void push(int x) {
        ListNode node = new ListNode(x, null, stack);
        stack.next = node;
        stack = node;
        
        map.putIfAbsent(x, new ArrayList<>());
        map.get(x).add(node);
    }
    
    public int pop() {
        int val = stack.val;
        removeNode(stack);
        return val;
    }
    
    public int top() {
        return stack.val;
    }
    
    public int peekMax() {
        return map.lastEntry().getKey();
    }
    
    public int popMax() {
        int max = peekMax();
        List<ListNode> nodeList = map.get(max);
        // System.out.println(nodeList.get(nodeList.size()-1).val);
        removeNode(nodeList.get(nodeList.size()-1));
        return max;
    }
    
    private void removeNode(ListNode node) {
        List<ListNode> nodeList = map.get(node.val);
        nodeList.remove(nodeList.size()-1);
        if (nodeList.isEmpty())
            map.remove(node.val);
        
        node.prev.next = node.next;
        if (node.next != null)
            node.next.prev = node.prev;
        
        if (node == stack)
            stack = stack.prev;
    }
    
    private void printList() {
        ListNode p = stack;
        while (p != null) {
            System.out.print(p.val + ",");
            p = p.prev;
        }
        System.out.println();
    }
    
    private static class ListNode {
        public int val;
        public ListNode next;
        public ListNode prev;
        
        public ListNode(int val, ListNode next, ListNode prev) {
            this.val = val;
            this.next = next;
            this.prev = prev;
        }
    }
}

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack obj = new MaxStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.peekMax();
 * int param_5 = obj.popMax();
 */
