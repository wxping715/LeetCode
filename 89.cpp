class Solution {
public:

    // a simpler method, find regularity of numbers
    vector<int> grayCode(int n) {
        vector<int> res;
        if (n < 0) return res;
        
        res.push_back(0);
        int prod = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = res.size()-1; j >= 0; j--) {
                res.push_back(prod + res[j]);
            }
            prod <<= 1;
        }
        return res;
    }
    
};
