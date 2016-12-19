class Solution {
public:

    typedef long long int LL;
    string fractionToDecimal(int numerator, int denominator) {
        if (denominator == 0) return "";
        
        string res = "";
        LL a = numerator, b = denominator; 
        if ((a < 0 && b > 0) || (a > 0 && b < 0)) res.push_back('-');
        
        a = abs(a); b = abs(b);
        res += to_string(a/b);
        if (a % b == 0) return res;
        
        res.push_back('.');
        unordered_map<int, int> idxmap;
        // cout << a << " " << b << endl;
        for (LL r = a%b; r ; r %= b) {
            // cout << a << " " << b << endl;
            if (idxmap.count(r) > 0) {
                res.insert(res.begin()+idxmap[r], '(');
                res.push_back(')');
                break;
            }
            idxmap[r] = res.size();
            r *= 10;
            res.push_back('0'+r/b);
        }
        return res;
    }
};
