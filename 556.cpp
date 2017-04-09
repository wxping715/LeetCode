class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        auto ns = stoll(nextPermutation(s));
        return (ns > INT_MAX || ns == n) ? -1 : res; 
    }
    
   /* For repeated numbers, like: 3731
      If we swap the first 3 and the second 3, then the next number must be smaller or equal to orginal number, it's useless
      So we only change greater numbers
   */
    string nextPermutation(string s) {
        if (s.length() < 2) return s;
        
        int i = s.length()-2, j = 0;
        while (i >= 0 && s[i] >= s[i+1]) i--;
        // did not find such pair
        if (i == -1) return s;
        
        j = i+1;
        while (j < s.length() && s[j] > s[i]) j++;
        
        //j-1 is the place
        swap(s[i], s[j-1]);
        
        int sk = i+1, ek = s.length()-1;
        while (sk <= ek) swap(s[sk++], s[ek--]);
        
        return s;
    }
};
