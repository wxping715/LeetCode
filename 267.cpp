/*Given a string s, return all the palindromic permutations (without duplicates) of it. Return an empty list if no palindromic permutation could be form.

For example:

Given s = "aabb", return ["abba", "baab"].

Given s = "abc", return [].

Hint:

If a palindromic permutation exists, we just need to generate the first half of the string.
To generate all distinct permutations of a (half of) string, use a similar approach from: Permutations II or Next Permutation.*/


class Solution {
public:
    // iterative
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
    
    vector<string> generatePalindromes(string s) {
        unordered_map<char, int> hashmap;
        vector<string> res;
        for (char ch : s) {
            hashmap[ch]++;
        }
        
        char och = -1;
        for (auto it : hashmap)
            if (it.second & 1) {
                if (och == -1) och = it.first;
                else return res;
            }
        
        string t = "";
        if (och != -1) {
            t.push_back(och);
            hashmap[och]--;
        }
        
        generate(hashmap, t, res);
        return res;
    }
    
    // backtracing
    void generate(unordered_map<char, int>& hashmap, string s, vector<string>& res) {
        bool found = false;
        for (auto it : hashmap) {
            if (it.second) {
                found = true;
                hashmap[it.first] -= 2;
                generate(hashmap, it.first+s+it.first, res);
                hashmap[it.first] += 2;
            }
        }
        
        if (!found) res.push_back(s);
    }
};
