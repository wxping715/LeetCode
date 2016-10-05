class Solution {
public:

    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        if (num > 8 || num < 0) return res;
        
        int status[10] = {0};
        dfs(status, num, 0, res);
        return res;
    }
    
    void dfs(int status[], int re, int curIdx, vector<string>& res) {
        if (re <= 0) {
            convert(status, res);
            return;
        }
        if (curIdx + re > 10) return;
        for (int i = curIdx; i <= 10 - re; i++) {
            status[i] = 1;
            dfs(status, re-1, i+1, res);
            status[i] = 0;
        }
    }
    
    void convert(int status[], vector<string>& res) {
        int h = 0, m = 0, prod = 1;
        for (int i = 3; i >= 0; i--) {
            h += prod * status[i];
            prod <<= 1;
        }
        
        prod = 1;
        for (int i = 9; i >= 4; i--) {
            m += prod * status[i];
            prod <<= 1;
        }
        
        if (h > 11 || m > 59) return;
        string time = to_string(h);
        time.push_back(':');
        if (m < 10) time.push_back('0');
        time += to_string(m);
        
        res.push_back(time);
    }
};
