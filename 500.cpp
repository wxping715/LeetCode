class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        for (string word : words) {
            int r = 0;
            bool ok = true;
            for (char ch : word) {
                if (ch >= 'a' && ch <= 'z') ch = ch - 'a' + 'A';
                if (r != 0 && hashmap[ch] != r) {
                    ok = false;
                    break;
                }
                r = hashmap[ch];
            }
            if (ok)
                res.push_back(word);
        }
        return res;
    }
private:
    unordered_map<char, int> hashmap {{'Q', 1}, {'W', 1}, {'E', 1}, {'R', 1}, {'T', 1}, {'Y', 1}, {'U', 1}, {'I', 1}, {'O', 1}, {'P', 1}, {'A', 2}, {'S', 2}, {'D', 2}, {'F', 2}, {'G', 2}, {'H', 2}, {'J', 2}, {'K', 2}, {'L', 2}, {'Z', 3}, {'X', 3},
        {'C', 3}, {'V', 3}, {'B', 3}, {'N', 3}, {'M', 3}};
};
