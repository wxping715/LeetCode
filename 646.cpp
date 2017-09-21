class Solution {
public:
    
    struct Comp {
        bool operator() (vector<int>& p1, vector<int> &p2) {
            if (p1[0] == p2[0]) return p1[1] < p2[1];
            return p1[0] < p2[0];
        }
    };
    
    // O(n^2)
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), Comp());
        vector<int> dp(pairs.size(), 1);
        for (int i = 1; i < pairs.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (pairs[j][1] < pairs[i][0])
                    dp[i] = max(dp[i], dp[j]+1);
            }
        }
        int n = pairs.size();
        return dp[n-1];
    }
    
    struct Comp {
        bool operator() (vector<int>& p1, vector<int> &p2) {
            return p1[1] < p2[1];
        }
    };
    
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), Comp());
        int i = -1, maxl = 0, r;
        while (++i < pairs.size()) {
            maxl++;
            r = pairs[i][1];
            while (i+1 < pairs.size() && pairs[i+1][0] <= r)
                i++;
        }
        return maxl;
    }
};
