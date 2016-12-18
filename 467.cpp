class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int cnt[26] = {0}, cur = 0;
        for (int i = 0; i < p.length(); i++) {
            if (i > 0 && (p[i]-p[i-1] == 1 || p[i-1]-p[i] == 25))
                cur++;
            else
                cur = 1;
            cnt[p[i]-'a'] = max(cnt[p[i]-'a'], cur);
        }
        
        int res = 0;
        for (int i = 0; i < 26; i++) {
            res += cnt[i];
        }
        return res;
    }
};
