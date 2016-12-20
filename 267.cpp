/*Given a string s, return all the palindromic permutations (without duplicates) of it. Return an empty list if no palindromic permutation could be form.

For example:

Given s = "aabb", return ["abba", "baab"].

Given s = "abc", return [].

Hint:

If a palindromic permutation exists, we just need to generate the first half of the string.
To generate all distinct permutations of a (half of) string, use a similar approach from: Permutations II or Next Permutation.*/


class Solution {
public:
    vector<string> generatePalindromes(string s) {
        int hash[256] = {0};
        for (char ch : s)
            hash[ch]++;
        
        vector<string> res;
        bool odd = false;
        string oddch;
        string half = "";
        for (int i = 0; i < 256; i++) {
            if (hash[i]&1) {
                if (odd) return res;
                odd = true;
                oddch.push_back(i);
            } 
            half += string(hash[i]/2, i);
        }
        
        sort(half.begin(), half.end());
        do {
            string shalf(half);
            reverse(shalf.begin(), shalf.end());
            res.push_back(half + (odd ? oddch : "" ) + shalf);
        } while (next_permutation(half.begin(), half.end()));
        return res;
    }
};
