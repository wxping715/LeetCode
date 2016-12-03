class Solution {
public:
    string getHint(string secret, string guess) {
        int hash[10] = {0}, bulls[10] = {0};
        int bullcnt = 0, cowcnt = 0;
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                bullcnt++;
                bulls[secret[i]-'0']++;
            }
            else 
                hash[secret[i]-'0']++;
        }
        
        for (char ch : guess) {
            if (bulls[ch-'0'] > 0) bulls[ch-'0']--;
            else if (hash[ch-'0'] > 0) {
                cowcnt++;
                hash[ch-'0']--;
            }
        }
        
        return to_string(bullcnt)+"A"+to_string(cowcnt)+"B";
    }
};
