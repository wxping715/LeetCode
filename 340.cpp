/*Given a string, find the length of the longest substring T that contains at most k distinct characters.

For example, Given s = “eceba” and k = 2,

T is "ece" which its length is 3.

Show Company Tags
Show Tags
Show Similar Problems*/


class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int lidx = 0, cidx = 0;
        unordered_map<char, int> hashmap;
        int res = 0;
        while (cidx < s.length()) {
            hashmap[s[cidx]]++;
            if (hashmap.size() > k) {
                res = max(res, cidx-lidx);
                while (hashmap.size() > k) {
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
