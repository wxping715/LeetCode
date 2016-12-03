class Solution {
public:
    // dp[i] means the substring ending with i is one valid string
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        for (int i = 1 ; i <= s.length(); i++) {
            for (int j = i-1; j >= 0; j--) {
                if (!dp[j]) continue;
                if (wordDict.find(s.substr(j, i-j)) != wordDict.end()) {
                    dp[i] = true;
                    break;
                }
            } 
        }
        return dp[s.size()];
    }
};
