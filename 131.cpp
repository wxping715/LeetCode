class Solution {
public:

     bool ispalindrome(string s){
        int len = s.length();
        for(int i = 0;i < len/2;i++)
            if(s[i] != s[len-1-i])
                return false;
        return true;
    }
    
    void dfs(string s,vector<vector<string> > &res, vector<string> path){
        if(s == "" && path.size() != 0){
            vector<string> v = path;
            res.push_back(v);
        }else if(s == "") return;
        
        for(int i = 1;i <= s.size();i++){
            string now = s.substr(0,i);
            string left = s.substr(i,s.size()-i);
            if(ispalindrome(now)){
                path.push_back(now);
                dfs(left,res,path);
                path.erase(path.begin()+path.size()-1);
            }
        }
    }
    
    vector<vector<string> > partition(string s) {
        vector<vector<string> > ans;
        vector<string> path;
        dfs(s,ans,path);
        
        return ans;
    }
};
