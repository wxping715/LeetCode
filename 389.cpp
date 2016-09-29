class Solution {
public:

    // my initial solution
    char findTheDifference(string s, string t) {
        int freq[26] = {0};
        for (int i = 0; i < s.length(); i++)
            freq[s[i]-'a']++;
        for (int i = 0; i < t.length(); i++) {
            if (freq[t[i]-'a'] == 0) return t[i];
            freq[t[i]-'a']--;
        }
        return 'a';
    }
    
    //easy method
    char findTheDifference(string s, string t) {
        int sum = 0;
        for (int i = 0; i < s.length(); i++) {
            sum += t[i];
            sum -= s[i];
        }
        sum += t.back();
        return sum;
    }
};
