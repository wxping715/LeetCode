class Solution {
    unordered_map<int, string> hash = {
        {0, "Zero"}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"},
        {9, "Nine"}, {10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"}, {20, "Twenty"}, {30, "Thirty"}, {40, "Forty"},
        {50, "Fifty"}, {60, "Sixty"}, {70, "Seventy"}, {80, "Eighty"}, {90, "Ninety"}
    };
    
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        
        string unit[] = {"","Thousand", "Million", "Billion"};
        int idx = 0;
        vector<string> tokens;
        while (num) {
            int m = num%1000;
            if (m != 0) {
                if (idx != 0) tokens.push_back(unit[idx]);
                string tres = tdigits(m);
                tokens.push_back(tres);
            }
            
            num/=1000;
            idx++;
        }
        
        string res = "";
        reverse(tokens.begin(), tokens.end());
        for (int i = 0; i < tokens.size(); i++) {
            if (i != 0) res += " ";
            res += tokens[i];
        }
        return res;
    }
    
    string tdigits(int num) {
        if (num == 0) return hash[num];
        
        vector<string> tokens;
        int m = num/100;
        if (m) {
            tokens.push_back(hash[m]);
            tokens.push_back("Hundred");
        }
        num %= 100;
        
        m = num/10;
        if (num && m) {
            if (m == 1 || num%10==0) tokens.push_back(hash[num]);
            else tokens.push_back(hash[m*10]);
        }
        
        num %= 10;
        if (num && m != 1) {
            tokens.push_back(hash[num]);
        }
        
        string res = "";
        for (int i = 0; i < tokens.size(); i++) {
            if (i != 0) res += " ";
            res += tokens[i];
        }
        return res;
    }
};
