class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        
        vector<int> v1;
        v1.push_back(1);
        
        vector<int> v2;
        v2.push_back(1);
        v2.push_back(1);
        
        vector<vector<int>> res;
        
        if(numRows == 0) return res;
        res.push_back(v1);
        if(numRows == 1) return res;
        res.push_back(v2);
        if(numRows == 2) return res;
        
        for(int i = 2;i < numRows;i++)
        {
            vector<int> v;
            v.push_back(1);
            for(int j = 1;j < i;j++)
                v.push_back(res[i-1][j-1] + res[i-1][j]);
            v.push_back(1);
            
            res.push_back(v);
        }
        return res;
    }
};