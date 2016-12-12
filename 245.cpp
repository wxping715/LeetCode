class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int idx1 = -1, idx2 = -1, res = words.size();
        bool first = true;
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word1 && (word1 != word2 || first)) {
                idx1 = i;
                first = false;
            }
            else if (words[i] == word2 && (word1 != word2 || !first)) {
                idx2 = i;
                first = true;
            }
            
            if (idx1 != -1 && idx2 != -1)
                res = min(res, abs(idx1-idx2));
        }
        return res;
    }
};
