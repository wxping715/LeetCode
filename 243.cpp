class Solution {
public:
    // int shortestDistance(vector<string>& words, string word1, string word2) {
    //     unordered_map<string, vector<int>> hash;
    //     for (int i = 0; i < words.size(); i++) {
    //         hash[words[i]].push_back(i);
    //     }
        
    //     vector<int> idx1 = hash.find(word1)->second;
    //     vector<int> idx2 = hash.find(word2)->second;
        
    //     int res = words.size();
    //     int i = 0, j = 0;
    //     while (i < idx1.size() && j < idx2.size()) {
    //         while (i < idx1.size() && idx1[i] < idx2[j]) {
    //             res = min(res, abs(idx1[i]-idx2[j]));
    //             i++;
    //         }
            
    //         while (j < idx2.size() && idx2[j] < idx1[i]) {
    //             res = min(res, abs(idx1[i]-idx2[j]));
    //             j++;
    //         }
    //     }
        
    //     return res;
    // }
    
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
};
