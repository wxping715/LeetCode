/*
Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
*/

class Solution {
public:
    string frequencySort(string s) {
        int hashmap[256] = {0}, maxFreq = 0;
        for (char ch : s) {
            hashmap[ch]++;
            maxFreq = max(maxFreq, hashmap[ch]);
        }
    
        vector<vector<char>> sortedChars(maxFreq+1, vector<char>());
        for (int i = 0; i < 256; i++)
            if (hashmap[i] > 0)
                sortedChars[hashmap[i]].push_back(i);
        
        string res = "";
        for (int i = maxFreq; i >= 1; i--)
            for (char ch : sortedChars[i]) {
                int k = i;
                while (k--) res.push_back(ch);
            }
        return res;
    }
};
