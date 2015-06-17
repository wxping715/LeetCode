class Solution {
public:

    string findPStringLength(string s,int r1,int r2)
    {
        int l = r1,r = r2;
        while(l >= 0 && r < s.length() && s[l] == s[r]){
            l--;
            r++;
        }
        return s.substr(l+1,r-l-1);
    }

    string longestPalindrome(string s) {
        
        if(s.length() <= 1) return s; 
        
        int ans = 1;
        string res;
        
        for(int i = 0;i < s.length();i++){
            string t = findPStringLength(s,i,i);
            if(t.length() > ans){
                ans = t.length();
                res = t;
            }
        }
        for(int i = 0;i < s.length()-1;i++){
            string t = findPStringLength(s,i,i+1);
            if(t.length() > ans){
                ans = t.length();
                res = t;
            }
        }
        return res;
    }
};
