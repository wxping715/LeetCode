class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> s(words.begin(), words.end());
        vector<string> res;
        
        for (string word : words) {
            int len = word.length();
            vector<int> dp(len+1, 0);
            dp[0] = 1;
            for (int i = 0; i < len; i++) {
                if (dp[i] == 0) continue;
                for (int j = i+1; j <= len; j++) {
                    if (j-i < len && s.count(word.substr(i, j-i))) dp[j] = 1;
                }
                if (dp[len]) {
                    res.push_back(word);
                    break;
                }
            }
        }
        return res;
    }
};
