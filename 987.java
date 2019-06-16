/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

// version 1
// class Solution {
//     public List<List<Integer>> verticalTraversal(TreeNode root) {
//         Map<Integer, List<Integer>> hashmap = new HashMap();
//         Queue<Tuple> queue = new LinkedList();
//         int miny = 0, maxy = 0;
//         if (root == null) return Collections.emptyList();
//         queue.offer(new Tuple(root, 0, 0));
//         while (!queue.isEmpty()) {
//             int n = queue.size();
//             Map<Integer, List<Integer>> levelHashMap = new HashMap<>();
//             while ((n--) > 0) {
//                 Tuple poll = queue.poll();
//                 miny = Math.min(poll.y, miny);
//                 maxy = Math.max(poll.y, maxy);
                
//                 List<Integer> vals = levelHashMap.getOrDefault(poll.y, new ArrayList());
//                 vals.add(poll.node.val);
//                 levelHashMap.put(poll.y, vals);
//                 if (poll.node.left != null) queue.offer(new Tuple(poll.node.left, poll.x+1, poll.y-1));
//                 if (poll.node.right != null) queue.offer(new Tuple(poll.node.right, poll.x+1, poll.y+1));
//             }
            
//             for (Map.Entry<Integer, List<Integer>> entry : levelHashMap.entrySet()) {
//                 Collections.sort(entry.getValue());
//                 List<Integer> vals = hashmap.getOrDefault(entry.getKey(), new ArrayList());
//                 vals.addAll(entry.getValue());
//                 hashmap.put(entry.getKey(), vals);
//             }
//         }
        
//         List<List<Integer>> result = new ArrayList();
//         for (int i = miny; i <= maxy; i++) {
//             List<Integer> vals = hashmap.getOrDefault(i, null);
//             if (vals != null) {
//                 result.add(vals);
//             }
//         }
//         return result;
//     }
    
//     private class Tuple {
//         TreeNode node;
//         int x;
//         int y;
        
//         public Tuple(TreeNode node, int x, int y) {
//             this.node = node;
//             this.x = x;
//             this.y = y;
//         }
//     }
// }

class Solution {
    public List<List<Integer>> verticalTraversal(TreeNode root) {
        if (root == null) return Collections.emptyList();
        List<Location> locations = new ArrayList();
        dfs(root, 0, 0, locations);
        Collections.sort(locations);
        
        List<List<Integer>> result = new ArrayList<>();
        result.add(new ArrayList());
        int prey = locations.get(0).y;
        for (Location location : locations) {
            if (location.y != prey) {
                result.add(new ArrayList());
                prey = location.y;
            }
            result.get(result.size()-1).add(location.val);
        }
        return result;
    }
    
    void dfs(TreeNode root, int x, int y, List<Location> locations) {
        if (root == null) return;
        locations.add(new Location(x, y, root.val));
        if (root.left != null) dfs(root.left, x+1, y-1, locations);
        if (root.right != null) dfs(root.right, x+1, y+1, locations);
    }
    
    private class Location implements Comparable<Location> {
        int x, y, val;
        Location(int x, int y, int val) {
            this.x = x;
            this.y = y;
            this.val = val;
        }
        
        @Override
        public int compareTo(Location that) {
            if (this.y != that.y) return Integer.compare(this.y, that.y);
            if (this.x != that.x) return Integer.compare(this.x, that.x);
            return Integer.compare(this.val, that.val);
        }
    }
}
