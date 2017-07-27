/*
Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “coding”, word2 = “practice”, return 3.
Given word1 = "makes", word2 = "coding", return 1.

Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
*/

class Solution {
public:
    
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int idx1 = -1, idx2 = -1, res = words.size();
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word1) idx1 = i;
            if (words[i] == word2) idx2 = i;
            
            if (idx1 != -1 && idx2 != -1)
                res = min(res, abs(idx1-idx2));
        }
        return res;
    }
    
    // one pointer
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int i = -1, j = 0, res = words.size();
        for (; j < words.size(); j++) {
            if (word1 == words[j] || word2 == words[j]) {
                if (i != -1 && words[i] != words[j])
                    res = min(res, j-i);
                i = j;
            }
        }
        return res;
    }
};
