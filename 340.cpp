/*Given a string, find the length of the longest substring T that contains at most k distinct characters.

For example, Given s = “eceba” and k = 2,

T is "ece" which its length is 3.

Show Company Tags
Show Tags
Show Similar Problems*/


class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) { 
        int l = 0, r = -1;
        unordered_map<char, int> hashmap;
        int res = 0;
        while (r < s.length()) {
            if (hashmap.size() > k) {
                hashmap[s[l]]--;
                if (hashmap[s[l]] == 0)
                    hashmap.erase(s[l]);
                l++;
            } else {
                res = max(r-l+1, res);
                r++;
                if (r < s.length())
                    hashmap[s[r]]++;
            }
        }
        return res;
    }
};
