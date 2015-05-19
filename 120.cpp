class Solution {
public:

    int min(int a,int b){
        return a < b ? a : b;
    }

    int minimumTotal(vector<vector<int> > &triangle) {
        vector<int> pre, cur, tmp;
        
        if(triangle.size() == 1) return triangle[0][0];
        
        pre = triangle[0];
        for(int i = 1;i < triangle.size();i++)
        {
            cur.clear();
            for(int j = 0;j <= i;j++){
                if(j == 0) cur.push_back(pre[j] + triangle[i][j]);
                else if(j == i) cur.push_back(pre[j-1] + triangle[i][j]);
                else cur.push_back(min(pre[j-1],pre[j])+triangle[i][j]);
            }
            
            tmp = pre;
            pre = cur;
            cur = tmp;
        }
        
        int res = 99999999, size = triangle.size();
        for(int i = 0;i < size;i++)
            res = res > pre[i] ? pre[i] : res;
        
        return res;
    }
};