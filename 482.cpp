class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string res = "";
        int cur = 0;
        for (int i = (int)S.length()-1; i >= 0; i--) {
            if (S[i] == '-') continue;
            
            //insert the dash
            if (cur == K) {
                res.push_back('-');
                cur = 0;
            }
            //insert the char
            if (S[i] >= 'a' && S[i] <= 'z') res.push_back(S[i]-'a'+'A');
            else res.push_back(S[i]);
            
            
            cur++;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
