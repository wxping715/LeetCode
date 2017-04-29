class Solution {
public:

    typedef pair<int, int> project;
    bool static compare(const project& p1, const project& p2) {
        return p1.second < p2.second;
    }    

    // nlogn + nlogn + nlogn + k*logn = nlogn
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        vector<project> projects;
        for (int i = 0; i < Profits.size(); i++)
            projects.emplace_back(Profits[i], Capital[i]);
        sort(projects.begin(), projects.end(), compare);
            
        std::multiset<int> pheap;
        int res = W, i = 0;
        for (int j = 0; j < k; j++) {
            while (i < projects.size() && projects[i].second <= res) {
                pheap.insert(projects[i++].first);
                if (pheap.size() > k) pheap.erase(pheap.begin());
            }
            
            if (!pheap.empty()) {
                int mprofit = *(pheap.rbegin());
                pheap.erase(--pheap.end());
                res += mprofit;
            }
        }
        return res;
    }
};
