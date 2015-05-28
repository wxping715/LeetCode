class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        set<char> myset;
        vector<char> v;
        
        for(int i = 0;i < board.size();i++){
            myset.clear();
            v = board[i];
            for(int j = 0;j < v.size();j++){
                if(v[j] == '.') continue;
                if(v[j] > '9' || v[j] < '1') return false;
                if(myset.find(v[j]) != myset.end()) return false;
                myset.insert(v[j]);
            }
        }
        
        for(int i = 0;i < board[0].size();i++){
            myset.clear();
            for(int j = 0;j < board.size();j++)
            {
                char val = board[j][i];
                if(val == '.')  continue;
                if(val > '9' || val < '1') return false;
                if(myset.find(val) != myset.end()) return false;
                myset.insert(val);
            }
        }
        
        for(int i = 0;i <= board.size()-3;i += 3)
            for(int j = 0;j <= board[0].size()-3;j += 3){
                myset.clear();
                
                for(int k = 0;k < 3;k++)
                    for(int m = 0;m < 3;m++)
                    {
                        char val = board[i+k][j+m];
                        if(val == '.')  continue;
                        if(val > '9' || val < '1') return false;
                        if(myset.find(val) != myset.end()) return false;
                        myset.insert(val);
                    }
            }
        
        return true;
    }
};
