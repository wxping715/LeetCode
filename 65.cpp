class Solution {
public:
    /*
    * 1. trim the string firstly
    * 2. cases:
    *       (1) the first char:
    *               a. '+' or '-' if next char is '.' or digital
    *               b. '.' if the next char is digital
    *               c. digital
    *       (2) other chars:
    *               a. digitals
    *               b. 'e' if 'e' have not appeared and the next char is digital or '+' or '-'
    *               c. '.' if neither 'e' nor '.' have appeared and the next char is digital or the previous char is digital
    *               d. '+' or '-' if and only if the privious char is 'e' and the next char is digital
    */
    bool isNumber(string s) {
        trim(s);
        if (s.length() == 0) return false;
        
        bool dot = false, e = false;
        for(int i = 0;i < s.length(); i++) {
            if (i == 0) {
                if ((s[i] == '+' || s[i] == '-') && s.length() > 1 && (s[i+1] == '.' || isDigital(s[i+1]))) {
                    continue;
                }
                else if (s[i] == '.' && s.length() > 1 && isDigital(s[i+1])) {
                    dot = true;
                    continue;
                }
                else if (isDigital(s[i])) continue;
                return false;
            }
            else {
                if (!dot && !e  && (s[i] == '.') && (((i+1 < s.length()) && (isDigital(s[i+1]))) || (isDigital(s[i-1])))) {
                    dot = true;
                    continue;
                }
                else if (!e && (s[i] == 'e') && (i+1 < s.length()) && (isDigital(s[i+1]) || s[i+1] == '+' || s[i+1] == '-')){
                    e = true;
                    continue;
                }
                else if (isDigital(s[i])) continue;
                else if ((s[i] == '+' || s[i] == '-') && (s[i-1] == 'e') && (i+1 < s.length()) && (isDigital(s[i+1]))) continue;
                return false;
            }
        }
        return true;
    }
    
    bool isDigital(char ch) {
        return ('0' <= ch) && (ch <= '9');
    }
    
    // trim from start
    static inline std::string &ltrim(std::string &s) {
            s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
            return s;
    }


    // trim from end
    static inline std::string &rtrim(std::string &s) {
            s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
            return s;
    }


    // trim from both ends
    static inline std::string &trim(std::string &s) {
            return ltrim(rtrim(s));
    }
    
};
