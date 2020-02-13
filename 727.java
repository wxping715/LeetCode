/*
727. Minimum Window Subsequence
Hard

470

24

Add to List

Share
Given strings S and T, find the minimum (contiguous) substring W of S, so that T is a subsequence of W.

If there is no such window in S that covers all characters in T, return the empty string "". If there are multiple such minimum-length windows, return the one with the left-most starting index.

Example 1:

Input: 
S = "abcdebdde", T = "bde"
Output: "bcde"
Explanation: 
"bcde" is the answer because it occurs before "bdde" which has the same length.
"deb" is not a smaller window because the elements of T in the window must occur in order.
 

Note:

All the strings in the input will only contain lowercase letters.
The length of S will be in the range [1, 20000].
The length of T will be in the range [1, 100].
*/

class Solution {
//     // O(2*M)*(M+N) == O(M*M)
//     public String minWindow(String S, String T) {
//         int l = 0;
//         String minString = "";
//         for (int r = 0; r < S.length(); r++) {
//             while (l <= r && check(S, l, r, T)) {
//                 if (minString.isEmpty() || minString.length() > (r-l+1))
//                     minString = S.substring(l, r+1);
//                 l++;
//             }
//         }
//         return minString;
//     }
    
//     // O(M+N)
//     private boolean check(String S, int l, int r, String T) {
//         int j = 0;
//         for (int i = l; i <= r; i++) {
//             if (S.charAt(i) == T.charAt(j))
//                 j++;
//             if (j == T.length())
//                 break;
//         }
//         // System.out.println(l + "," + r + "," + (j == T.length()));
//         return j == T.length();
//     }
    
     // O(M*N)
     public String minWindow(String S, String T) {
         int m = T.length(), n = S.length();
         int[][] dp = new int[m+1][n+1];
         for (int j = 0; j <= n; j++)
             dp[0][j] = j+1;
         
         for (int i = 1; i <= m; i++)
             for (int j = 1; j <= n; j++) {
                 if (T.charAt(i-1) == S.charAt(j-1))
                     dp[i][j] = dp[i-1][j-1];
                 else
                     dp[i][j] = dp[i][j-1];
             }
         
         int start = 0, len = n+1;
         for (int j = 1; j <= n; j++)
             if (dp[m][j] != 0)
                 if (j - dp[m][j] + 1 < len) {
                     len = j - dp[m][j] + 1;
                     start = dp[m][j] - 1;
                 }
         return len==n+1 ? "" : S.substring(start, start+len);
     }
}
