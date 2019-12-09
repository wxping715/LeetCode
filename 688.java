import java.lang.Math;

class Solution {
    public double knightProbability(int N, int K, int r, int c) {
        double[][] dp = new double[N][N];
        dp[r][c] = 1;
        
        int[] ax = new int[] {-2, -2, -1, 1, 2, 2, 1, -1};
        int[] ay = new int[] {-1, 1, 2, 2, 1, -1, -2, -2};
        for (int k = 1; k <= K; k++) {
            double[][] dp1 = new double[N][N];
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    for (int d = 0; d < 8; d++) {
                        int ni = i + ax[d];
                        int nj = j + ay[d];
                        
                        if (ni < 0 || ni >= N || nj < 0 || nj >= N)
                            continue;
                        dp1[i][j] += dp[ni][nj];
                    }
            dp = dp1;
        }
        
        double up = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                up += dp[i][j];
        return up / Math.pow(8, K);
    }
}
