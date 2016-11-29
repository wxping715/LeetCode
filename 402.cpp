class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k >= num.length()) return "0";
        
        while (k) {
            bool found = false;
            for (int i = 0; i < num.length()-1; i++)
                if (num[i] > num[i+1]) {
                    found = true;
                    num.erase(num.begin()+i);
                    break;
                }
            
            if (found) k--;
            else break;
        }
        
        if (k > 0) num.erase(num.begin()+num.length()-k,num.end());
        
        auto nzero_it = num.begin();
        while (nzero_it != num.end()) {
            if (*nzero_it != '0') break;
            nzero_it++;
        }
        num.erase(num.begin(), nzero_it);
        
        return num.size() == 0 ? "0" : num;
    }
};
