class Solution {
    public boolean isBipartite(int[][] graph) {
        int n = graph.length;
        // by default values is 0, -1 means red, 1 means blue
        int[] color = new int[n];
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            if (color[i] != 0) continue;
            queue.offer(i);
            color[i] = 1;
            while (!queue.isEmpty()) {
                int poll = queue.poll();
                for (int next : graph[poll]) {
                    if (color[next] != 0 && color[next] != -color[poll]) 
                        return false;
                    if (color[next] == 0) {
                        color[next] = -color[poll];
                        queue.offer(next);
                    }
                }
            }
        }
        return true;
    }
}
