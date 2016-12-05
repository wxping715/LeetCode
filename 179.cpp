class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if (nums.empty()) return "";
        
        vector<string> snums;
        for (int n : nums) snums.push_back(to_string(n));
        sort(snums.begin(), snums.end(), cmp);
        string res = "";
        for (string str : snums) res += str;
        
        int idx = 0;
        while (idx < res.length() && res[idx] == '0') idx++;
        if (idx == res.length()) idx--;
        res.erase(0, idx);
        return res;
    }
    
    static bool cmp(string a, string b) {
        return a+b > b+a;
    }
};
