class Solution {
    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        boolean[] visited = new boolean[rooms.size()];
        dfs(rooms, 0, visited);
        for (int i = 0; i < rooms.size(); i++)
            if (!visited[i])
                return false;
        return true;
    }
    
    private void dfs(List<List<Integer>> rooms, int v, boolean[] visited) {
        if (visited[v]) return;
        visited[v] = true;
        
        for (int v2 : rooms.get(v))
            dfs(rooms, v2, visited);
    }
}
