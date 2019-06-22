/*
We have a set of items: the i-th item has value values[i] and label labels[i].

Then, we choose a subset S of these items, such that:

|S| <= num_wanted
For every label L, the number of items in S with label L is <= use_limit.
Return the largest possible sum of the subset S.
*/

class Solution {
    public int largestValsFromLabels(int[] values, int[] labels, int num_wanted, int use_limit) {
        Map<Integer, List<Integer>> map = new HashMap<>();
        for (int i = 0; i < values.length; i++) {
            List<Integer> valueList = map.getOrDefault(labels[i], new ArrayList());
            valueList.add(values[i]);
            map.put(labels[i], valueList);
        }
        
        PriorityQueue<Pair> pq = new PriorityQueue<>(map.size(), (a, b) ->                      Integer.compare(map.get(b.key).get(b.index), map.get(a.key).get(a.index)));
        for (int key : map.keySet()) {
            Collections.sort(map.get(key), (a, b) -> Integer.compare(b, a));
            pq.offer(new Pair(key, 0));
        }
        int ans = 0;
        while ((num_wanted--) > 0 && !pq.isEmpty()) {
            Pair peek = pq.poll();
            ans += map.get(peek.key).get(peek.index);
            if (peek.index+1 < Math.min(use_limit, map.get(peek.key).size())) {
                pq.offer(new Pair(peek.key, peek.index+1));
            }
        }
        return ans;
    }
    
    private class Pair {
        int key;
        int index;
        
        public Pair(int key, int index) {
            this.key = key;
            this.index = index;
        }
    }
}
