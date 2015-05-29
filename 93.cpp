class Solution {
public:
    
    int convert(string s){
        if(s.length() != 1 && s[0] == '0') return -1;
        int ans = 0;
        for(int i = 0;i < s.length();i++)
            ans = ans * 10 + s[i] - '0';
        return ans;
    }

    void dfs(string s,int depth,vector<string> &v,string pstr){
        if(s.length() < 5-depth) return;

        if(depth == 4){
            int val = convert(s);
            if(val > 255 || val < 0) return;

            pstr += "." + s;
            v.push_back(pstr);
            
            return;
        }
        
        for(int i = 1;i <= 3;i++){
            if(i > s.length() - 1) return ;
            string now = s.substr(0,i);
            int val = convert(now);
            if(val > 255 || val < 0)
                continue;
            
            string tstr = pstr;
            if(depth != 1) tstr += ".";
            tstr += now;
            dfs(s.substr(i,s.length()-i),depth+1,v,tstr);
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> v;
        dfs(s,1,v,"");
        return v;
    }
};
