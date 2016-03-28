class Solution {
public:

    /*
    * O(NlogN)
    * original algorithm
    */
    int hIndex(vector<int>& citations) {
        if (citations.size() == 0) return 0;
        
        sort(citations.begin(), citations.end());
        int h = 1, len = citations.size(), res = 0;
        vector<int>::iterator lit;
        
        while (h <= citations[len-h]) {
            lit = lower_bound(citations.begin(), citations.end(), h);
            if (lit - citations.begin() <= len - h) {
                res = h;
            }
            h++;
        }
        return res;
    }
};


class Solution {
public:

    /*
    * O(NlogN)
    * brief algorithm
    */
    int hIndex(vector<int>& citations) {
        if (citations.size() == 0) return 0;
        
        sort(citations.begin(), citations.end());
        int i, n = citations.size();
        for (i = 0;i < n;i++) {
            if (citations[n-1-i] <= i) break;
        }
        return i;
    }
};


class Solution {
public:
    
    /*
    * O(N) Time, O(N) Space
    */
    int hIndex(vector<int>& citations) {
        if (citations.size() == 0) return 0;
        
        int n = citations.size();
        vector<int> cnt(n+1,0);
        for (int i = 0;i < n; i++) {
            if (citations[i] > n)
                cnt[n]++;
            else
                cnt[citations[i]]++;
        }
        
        int papers = 0;
        for (int i = n; i >= 0; i--) {
            papers += cnt[i];
            if (papers >= i)
                return i;
        }
    }
};
