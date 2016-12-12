class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        vector<string> res;
        if (n < 1) return res;
        
        string num(n,'0');
        genNum(res, num, 0, n-1);
        return res;
    }
    
    void genNum(vector<string>& res, string& num, int l, int r) {
        if (l > r) {
            string nnum(num);
            res.push_back(nnum);
            return;
        }
        
        int sidx = 0, eidx = 4;
        if (l == 0 && l != r) sidx = 1;
        if (l == r) eidx = 2;
        
        for (int i = sidx; i <= eidx; i++) {
            num[l] = left[i];
            num[r] = right[i];
            genNum(res, num, l+1, r-1);
        }
    }
private:
    char left[5] = {'0', '1', '8', '6', '9'};
    char right[5] = {'0','1', '8', '9', '6'};
};
