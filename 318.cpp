class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> flag(words.size());
        int res = 0;
        for (int i = 0; i < words.size(); i++) {
            for (char ch : words[i])
                flag[i] |= 1 << (ch-'a');
            for (int j = 0; j < i; j++)
                if (!(flag[i] & flag[j])) 
                    res = max(res, int(words[i].length() * words[j].length()));
        }
        return res;
    }
};
