/*
Given a list of strings words representing an English Dictionary, find the longest word in words that can be built one character at a time by other words in words. If there is more than one possible answer, return the longest word with the smallest lexicographical order.

If there is no answer, return the empty string.
Example 1:
Input: 
words = ["w","wo","wor","worl", "world"]
Output: "world"
Explanation: 
The word "world" can be built one character at a time by "w", "wo", "wor", and "worl".
Example 2:
Input: 
words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
Output: "apple"
Explanation: 
Both "apply" and "apple" can be built from other words in the dictionary. However, "apple" is lexicographically smaller than "apply".
Note:

All the strings in the input will only contain lowercase letters.
The length of words will be in the range [1, 1000].
The length of words[i] will be in the range [1, 30].
*/

class Solution {
public:
    
//     struct Comparsion {
//         bool operator() (const string& s1, const string& s2) {
//             if (s1.length() != s2.length()) return s1.length() > s2.length();
//             return s1 < s2;
//         }
//     };
    
//     // nlogn
//     string longestWord(vector<string>& words) {
//         sort(words.begin(), words.end(), Comparsion());
//         unordered_set<string> hashset;
//         for (string word : words)
//             hashset.insert(word);
        
//         for (string word : words) {
//             bool found = true;
//             string old_word = word;
//             while (!word.empty()) {
//                 if (!hashset.count(word)) {
//                     found = false;
//                     break;
//                 }
//                 word.pop_back();
//             }
//             if (found) return old_word;
//         }
//         return "";
//     }
    
    // O(n*k)
    string longestWord(vector<string>& words) {
        unordered_set<string> hashset;
        for (string word : words)
            hashset.insert(word);
        
        string res = "";
        for (string word : words) {
            string old_word = word;
            bool found = true;
            while (!word.empty()) {
                if (!hashset.count(word)) {
                    found = false;
                    break;
                }
                word.pop_back();
            }
            
            if (found && (old_word.length() > res.length() 
                          || (old_word.length() == res.length() && res > old_word)))
                res = old_word;
        }
        return res;
    }
};
