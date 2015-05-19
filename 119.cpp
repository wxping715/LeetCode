class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v0;
    
    vector<int> v1;
    v1.push_back(1);
        
    vector<int> v2;
    v2.push_back(1);
    v2.push_back(1);
        
    vector<int> pre;
    vector<int> cur;
        
    if(rowIndex == 0) return v1;
    if(rowIndex == 1) return v2;
    
    pre = v2;
    for(int i = 2;i <= rowIndex;i++)
    {
        cur.clear();
        cur.push_back(1);
        for(int j = 1;j < i;j++)
            cur.push_back(pre[j-1] + pre[j]);
        cur.push_back(1);
    
        v0 = pre;
        pre = cur;
        cur = v0;
    }
    return pre;   
    }
};