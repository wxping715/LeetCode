class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.length() != s1.length() + s2.length()) return false;
        if (lcs(s1, s3) != (int)s1.length()) return false;
        
        string rs = "";
        int j = 0;
        for (int i = 0; i < s3.length(); i++) {
            if (j < s1.length() && s1[j] == s3[i]) j++;
            else rs.push_back(s3[i]);
        }
        return rs == s2;
    }
    
    int lcs(string s1, string s2) {
        int len1 = s1.length(), len2 = s2.length();
        vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));
        
        for (int i = 1; i <= len1; i++)
            for (int j = 1; j <= len2; j++) {
                if (s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1]+1;
                else {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        return dp[len1][len2];
    }
};
