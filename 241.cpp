class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        if (input.empty()) return res;
        
        return search(input, 0, input.length()-1);
    }
    
    vector<int> search(string& s, int l, int r) {
        bool hasopr = false;
        vector<int> res;
        int number = 0;
        for (int i = l; i <= r; i++) {
            if (!isdigit(s[i])) {
                hasopr = true;
                vector<int> lres = search(s, l, i-1);
                vector<int> rres = search(s, i+1, r);
                
                for (int lopt : lres)
                    for (int ropt : rres) {
                        switch(s[i]) {
                            case '+':
                                res.push_back(lopt+ropt);
                                break;
                            case '-':
                                res.push_back(lopt-ropt);
                                break;
                            case '*':
                                res.push_back(lopt*ropt);
                                break;
                        }
                    }
            }
            else number = number * 10 + s[i]-'0';
        }
        if (!hasopr) res.push_back(number);
        return res;
    }
}; 
