/*
Given a list of words (without duplicates), please write a program that returns all concatenated words in the given list of words.

A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.

Example:
Input: ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]

Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]

Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats"; 
 "dogcatsdog" can be concatenated by "dog", "cats" and "dog"; 
"ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
Note:
The number of elements of the given array will not exceed 10,000
The length sum of elements in the given array will not exceed 600,000.
All the input string will only include lower case letters.
The returned elements order does not matter.

*/

class Solution {
public:

    // O(n*k^3)
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> hashset;
        for (string word : words)
            hashset.insert(word);
        
        vector<string> result;
        for (string word : words) {
            // dp[i] means if it is ok from 1 to i
            vector<int> dp(word.length()+1, false);
            dp[0] = true;
            // i means the length of right part
            for (int i = 1; i <= word.length(); i++) {
                int j;
                for (j = i-1; j >= 0; j--) {
                    // dp[j] from 0 to j-1
                    // cur: from j to i-1
                    string cur = word.substr(j, i-j);
                    if (dp[j] && hashset.count(cur)) {
                        dp[i] = true;
                        break;
                    }
                }
                
                if (i == word.length() && j != 0)
                    result.push_back(word);
            }
        }
        return result;
    }
};
