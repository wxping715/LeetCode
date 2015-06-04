class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if(strs.size() < 1) return "";
        if(strs.size() == 1) return strs[0];
        
        set<string> myset;
        for(int i = 1;i <= strs[0].length();i++)
            myset.insert(strs[0].substr(0,i));
        int end = strs[0].length();
        
        for(int i = 1;i < strs.size();i++){
            string s = strs[i];
            
            if(s.length() < end) end = s.length();
            
            while(end > 0 && myset.find(s.substr(0,end)) == myset.end()){
                end--;
            }   
        }
        
        return strs[0].substr(0,end);
    }
};
