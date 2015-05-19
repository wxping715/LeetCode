class Solution {
public:
    int titleToNumber(string s) {
        int ans = 0,l = s.length();
        for(int i = 0;i < l;i++)
            ans = ans*26 + (s[i]-'A'+1);
        return ans;
    }
};