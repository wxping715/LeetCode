class Solution {
public:
    string getPermutation(int n, int k) {
        if (n < 0 || k <= 0) return "";
        
        int fac[n+1];
        fac[0] = 1;
        for (int i = 1; i < n; i++)
            fac[i] = fac[i-1]*i;
            
        vector<char> items;
        for (int i = 1; i <= n; i++)
            items.push_back(i+'0');
            
        if (k > fac[n-1]*n) return "";
        
        int re = k-1;
        string res = "";
        for (int i = 1; i <= n; i++) {
            int d = re / fac[n-i];
            re %= fac[n-i];
            
            res.push_back(items[d]);
            items.erase(items.begin()+d);
        }
        return res;
    }
};
