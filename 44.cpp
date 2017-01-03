class Solution {
public:
    bool isMatch(string s, string p) {
        vector<bool> dp(s.length(), false);
        dp[0] = true;
        for (int j = 1; j <= p.length(); j++) {
            bool pre = dp[0];  //dp[i-1][j-1]
            dp[0] = dp[0] && p[j-1] == '*';
            for (int i = 1; i <= s.length(); i++) {
                bool cur = dp[i]; // dp[i][j-1]
                if (p[j-1] == '?') dp[i] = pre;
                else if (p[j-1] != '*') dp[i] = (s[i-1] == p[j-1] && pre);
                else dp[i] = dp[i] | dp[i-1];
                pre = cur;
            }
        }
        return dp[s.length()];
    }
};
