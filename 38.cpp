class Solution {
public:
    string countAndSay(int n) {
        if(n == 0) return "";
        if(n == 1) return "1";
        
        vector<int> v1,v2;
        v1.push_back(1);
        
        for(int i = 1;i < n;i++){
            v2.clear();
            int cnt = 0;
            int pre = v1[0];
            
            for(int j = 0;j < v1.size();j++){
                if(v1[j] != pre){
                    v2.push_back(cnt);
                    v2.push_back(pre);
                    cnt = 1;
                    pre = v1[j];
                }else{
                    cnt++;
                }
            }
            v2.push_back(cnt);
            v2.push_back(pre);
            
            vector<int> tmp;
            tmp = v1;
            v1 = v2;
            v2 = tmp;
        }
        
        string res = "";
        for(int i = 0;i < v1.size();i++){
            stringstream s;
            s<<v1[i];
            res += s.str();
        }
        
        return res;
    }
};
