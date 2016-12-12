class WordDistance {
public:
    WordDistance(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            hash[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        vector<int> idx1 = hash.find(word1)->second;
        vector<int> idx2 = hash.find(word2)->second;
        
        int res = 0x3fffffff;
        int i = 0, j = 0;
        while (i < idx1.size() && j < idx2.size()) {
            res = min(res, abs(idx1[i]-idx2[j]));
            if (idx1[i] < idx2[j]) i++;
            else j++;
        }
        return res;
    }
    
private:
    unordered_map<string, vector<int>> hash;
};


// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");
