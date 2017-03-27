class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int a1, b1, a2, b2;
        
        int i = a.find("+");
        int j = b.find("+");
        a1 = stoi(a.substr(0, i)), b1 = stoi(a.substr(i+1, a.length()-i-1));
        a2 = stoi(b.substr(0, j)), b2 = stoi(b.substr(j+1, b.length()-j-1));
        
        int ra = a1*a2 - b1*b2, rb = a1*b2 + a2*b1;
        return to_string(ra) + "+" + to_string(rb) + "i";
    }
};
