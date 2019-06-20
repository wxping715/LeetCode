/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public int[] nextLargerNodes(ListNode head) {
        Map<Integer, Integer> nextMap = new HashMap<>();
        // increased stack
        Stack<Pair> stack = new Stack();
        ListNode p = head;
        int index = 0;
        while (p != null) {
            while (!stack.empty()) {
                Pair peek = stack.peek();
                if (peek.val >= p.val)
                    break;
                nextMap.put(peek.index, p.val);  
                stack.pop();
            }
            stack.push(new Pair(index, p.val));
            p = p.next;
            index += 1;
        }
        
        int[] result = new int[index];
        for (Map.Entry<Integer, Integer> entry : nextMap.entrySet()) {
            result[entry.getKey()] = entry.getValue();
        }
        return result;
    }
    
    private class Pair {
        int index;
        int val;
        
        public Pair(int index, int val) {
            this.index = index;
            this.val = val;
        }
    }
}
