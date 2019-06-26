class Solution {
    private int count = 0;
    
    public int numEnclaves(int[][] A) {
        int ans = 0, m = A.length, n = A[0].length;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (A[i][j] == 1) {
                    count = 0;
                    if (!dfs(A, m, n, i, j)) {
                        ans += count;
                    }
                }
            }
        return ans;
    }
    
    private boolean dfs(int[][] A, int m, int n, int x, int y) {
        if (x < 0 || x >= m || y < 0 || y >= n)  return true;
        if (A[x][y] == 0) return false;
        A[x][y] = 0;
        
        count++;
        boolean result = false;
        result = result | dfs(A, m, n, x-1, y);
        result = result | dfs(A, m, n, x, y+1);
        result = result | dfs(A, m, n, x+1, y);
        result = result | dfs(A, m, n, x, y-1);
        return result;
    }
}
