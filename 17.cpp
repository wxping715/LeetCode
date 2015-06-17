class Solution {
public:
    
    char cmap[10][10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    int total[10] = {0,0,3,3,3,3,3,4,3,4};
    
    vector<string> letterCombinations(string digits) {
        int now[10] = {0};
        int len = digits.length();
        vector<string> res;
        
        if(len < 1) return res;
        
        while(true){
            string s = "";
            for(int i = 0;i < len;i++)
                s.insert(s.length(),1,cmap[digits[i]-'0'][now[i]]);
            res.push_back(s);
            
            int k = len - 1;
            while(k >= 0){
                if(now[k] < total[digits[k]-'0']-1){
                    now[k]++;
                    break;
                }else{
                    now[k] = 0;
                    k--;
                }
            }
            if(k < 0) break;
        }
        
        return res;
    }
};
