class Solution {
public:
    int magicalString(int n) {
        string s = "1", t = "1";
        char cur = '1';
        int num = 1, cnt1 = 1, cnt = 1, j = 0;
        
        if (n == 0) return 0;
        if (n == 1) return 1;
        while (s.length() < n) {
            if (num == cnt) {
                cur = (cur == '1' ? '2' : '1');
                s.push_back(cur);
                num = 1;
                cnt = s[++j] - '0';
            } else {
                s.push_back(cur);
                num++;
            }
            if (cur == '1') cnt1++;
        }
        return cnt1;
    }
};
