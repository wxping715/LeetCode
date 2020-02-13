/*
1168. Optimize Water Distribution in a Village
Hard

205

7

Add to List

Share
There are n houses in a village. We want to supply water for all the houses by building wells and laying pipes.

For each house i, we can either build a well inside it directly with cost wells[i], or pipe in water from another well to it. The costs to lay pipes between houses are given by the array pipes, where each pipes[i] = [house1, house2, cost] represents the cost to connect house1 and house2 together using a pipe. Connections are bidirectional.

Find the minimum total cost to supply water to all houses.

Input: n = 3, wells = [1,2,2], pipes = [[1,2,1],[2,3,1]]
Output: 3
Explanation: 
The image shows the costs of connecting houses using pipes.
The best strategy is to build a well in the first house with cost 1 and connect the other houses to it with cost 2 so the total cost is 3.
*/

class Solution {
    public int minCostToSupplyWater(int n, int[] wells, int[][] pipes) {
        List<int[]> allPipes = new ArrayList<>();
        for (int[] pipe : pipes)
            allPipes.add(pipe);
        for (int i = 0; i < n; i++)
            allPipes.add(new int[]{0, i+1, wells[i]});
        Collections.sort(allPipes, (p1, p2) -> {
            return Integer.compare(p1[2], p2[2]);   
        });
        
        int[] parent = new int[n+1];
        for (int i = 0; i <= n; i++)
            parent[i] = i;
        
        int result = 0, count = 0;
        for (int[] pipe : allPipes) {
            if (count >= n) break;
            int x = find(parent, pipe[0]), y = find(parent, pipe[1]);
            if (x != y) {
                result += pipe[2];
                count++;
                union(parent, x,y);
            }
        }
        return result;
    }
    
    private int find(int[] parent, int x) {
        if (x != parent[x]) {
            parent[x] = find(parent, parent[x]);
        }
        return parent[x];
    }
    
    private void union(int[] parent, int x, int y) {
        x = find(parent, x);
        y = find(parent, y);
        parent[x] = y;
    }
}
