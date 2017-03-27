class Solution {
public:
    bool detectCapitalUse(string word) {
        int capNum = 0;
        for (char ch : word) capNum += ('Z' >= ch ? 1 : 0);
        
        if (capNum == 0 || capNum == word.length()) return true;
        return ((capNum == 1) && (word[0] <= 'Z'));
    }
};
