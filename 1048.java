/*
Given a list of words, each word consists of English lowercase letters.

Let's say word1 is a predecessor of word2 if and only if we can add exactly one letter anywhere in word1 to make it equal to word2.  For example, "abc" is a predecessor of "abac".

A word chain is a sequence of words [word_1, word_2, ..., word_k] with k >= 1, where word_1 is a predecessor of word_2, word_2 is a predecessor of word_3, and so on.

Return the longest possible length of a word chain with words chosen from the given list of words.

 

Example 1:

Input: ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: one of the longest word chain is "a","ba","bda","bdca".
*/

class Solution {
    // dp(j) max length ending with j
    // dp(j) = max(dp(i) + 1) when i is predecessor of j
    public int longestStrChain(String[] words) {
        Arrays.sort(words, (a, b) -> Integer.compare(a.length(), b.length()));
        int n = words.length;
        int[] dp = new int[n];
        int ans = 0;
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (check(words[j], words[i])) {
                    dp[i] = Math.max(dp[i], dp[j]+1);
                }
            }
            ans = Math.max(ans, dp[i]);
        }
        return ans;
    }
    
    private boolean check(String s, String t) {
        if (s.length()+1 != t.length()) return false;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == t.charAt(i))
                continue;
            return Objects.equals(s.substring(i, s.length()), t.substring(i+1, t.length()));
        }
        return true;
    }
}
