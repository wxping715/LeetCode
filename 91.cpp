class Solution {
public:
    /*
    * O(n) space
    * dp(i) = dp(i-1) + dp(i-2) # s[i-2]s[i-1] < 26 and s[i-2] != 0 and s[i-1] != 0
    *         dp(i-1)  # s[i-2]s[i-1] > 26
    *         dp(i-2)  # s[i-1] = 0
    */
    int numDecodings(string s) {
        if (s.length() == 0) return 0;
        
        int dp[s.length()+1];
        dp[0] = 1;
        dp[1] = '1' <= s[0] && s[0] <= '9' ? 1 : 0;
        for (int i = 2; i <= s.length(); i++) {
            if (s[i-1] == '0') {
                if (s[i-2] >= '1' && s[i-2] <= '2') dp[i] = dp[i-2];
                else dp[i] = 0;
            } else {
                if (s[i-2] == '1' || (s[i-2] == '2' and s[i-1] <= '6')) dp[i] = dp[i-1] + dp[i-2];
                else dp[i] = dp[i-1];
            }
        }
        return dp[s.length()];
    }
};



class Solution {
public:
    /*
    * O(n) space
    * dp(i) = dp(i-1) + dp(i-2) # s[i-2]s[i-1] < 26 and s[i-2] != 0 and s[i-1] != 0
    *         dp(i-1)  # s[i-2]s[i-1] > 26
    *         dp(i-2)  # s[i-1] = 0
    */
    int numDecodings(string s) {
        if (s.length() == 0) return 0;
        
        int pre2 = 1, pre1 = '1' <= s[0] && s[0] <= '9' ? 1 : 0, cur = pre1;
        for (int i = 2; i <= s.length(); i++) {
            if (s[i-1] == '0' && s[i-2] >= '1' && s[i-2] <= '2') cur = pre2;
            else if (s[i-1] == '0') cur = 0;
            else if (s[i-2] == '1' || (s[i-2] == '2' and s[i-1] <= '6')) cur = pre1 + pre2;
            else cur = pre1;
            pre2 = pre1;
            pre1 = cur;
        }
        return cur;
    }
};
