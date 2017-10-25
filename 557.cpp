/*
Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
*/
class Solution {
public:
    string reverseWords(string s) {    
        int l = -1;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ' || i+1 == s.length()) {
                if (l != -1) 
                    reverse(s.begin()+l, s.begin() + (s[i] == ' ' ? i : i+1));
                l = -1;
            }
            else if (l == -1) l = i;
        }
        return s;
    }
};
