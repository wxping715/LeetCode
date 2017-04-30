class Solution {
public:

    /*
    * O(m*n)
    */
    bool checkInclusion(string s1, string s2) {
        vector<int> hash(26, 0);
        int len1 = s1.length(), len2 = s2.length();
        
        if (len1 > len2) return false;
        for (char ch : s1)
            hash[ch-'a']++;
        
        int i = 0;
        vector<int> tmp = hash;
        while (i+len1 <= len2) {
            int j = 0;
            for (j = 0; j < len1; j++) {
                if (!tmp[s2[i+j]-'a']) break;
                tmp[s2[i+j]-'a']--;
            }
            
            if (j >= len1) return true;
            
            if (!hash[s2[i+j]-'a']) i += j+1;
            else i++;
            tmp = hash;
        }
        return false;
    }
    
    
    /*
    * O(n)
    */
    bool checkInclusion(string s1, string s2) {
        int l = 0, r = 0;
        vector<int> hash(26, 0), cur(26, 0);
        if (s1.length() > s2.length()) return false;
        
        for (char ch : s1)
            hash[ch-'a']++;
        
        while (r < s2.length()) {
            cur[s2[r]-'a']++;
            while (l <= r && !contain(hash, cur)) {
                cur[s2[l++]-'a']--;
            }
            if (r-l+1 == s1.length()) return true;
            r++;
        }
        return false;
    }
    
    bool contain(vector<int>& hash, vector<int>& cur) {
        for (int i = 0; i < 26; i++)
            if (cur[i] > hash[i])
                return false;
        return true;
    }
};
