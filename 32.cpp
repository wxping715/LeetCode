class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int>dp(s.length(), 0);
        int ret = 0;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == ')' && i-dp[i-1]-1 >= 0 && s[i-dp[i-1]-1] == '(') {
                dp[i] = dp[i-1]+2+(i-dp[i-1]-2 >= 0 ? dp[i-dp[i-1]-2] : 0);
                ret = max(ret, dp[i]);
            }
        }
        return ret;
    }
};
