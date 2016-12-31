class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> hash1, hash2;
        for (int num1 : A)
            for (int num2 : B)
                hash1[num1+num2]++;
        
        for (int num1 : C)
            for (int num2 : D)
                hash2[num1+num2]++;
        
        int ret = 0;
        for (auto it : hash1) 
            if (hash2.count(-it.first))
                ret += it.second * hash2[-it.first];
        return ret;
    }
};
