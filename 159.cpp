/*Given a string, find the length of the longest substring T that contains at most 2 distinct characters.

For example, Given s = “eceba”,

T is "ece" which its length is 3.*/

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int lidx = 0, cidx = 0;
        unordered_map<char, int> hashmap;
        int res = 0;
        while (cidx < s.length()) {
            hashmap[s[cidx]]++;
            if (hashmap.size() > 2) {
                res = max(res, cidx-lidx);
                while (hashmap.size() > 2) {
                    hashmap[s[lidx]]--;
                    if (hashmap[s[lidx]] == 0)
                        hashmap.erase(s[lidx]);
                    lidx++;
                }
            }
            cidx++;
        }
        res = max(res, cidx-lidx);
        return res;
    }
};
