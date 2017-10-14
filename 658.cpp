class Solution {
public:
    
    struct comparsion {
        bool operator() (const pair<int, int>& p1, const pair<int, int>& p2) {
            if (p1.second == p2.second) return p1.first < p2.first;
            return p1.second < p2.second;
        }
    };
    
//     // nlogk + klogk
//     vector<int> findClosestElements(vector<int>& arr, int k, int x) {
//         priority_queue<pair<int,int>, vector<pair<int, int>>, comparsion> pq;
        
//         for (int num : arr) {
//             pq.push(make_pair(num, abs(num-x)));
//             if (pq.size() > k) pq.pop();
//         }
        
//         vector<int> res;
//         while (!pq.empty()) {
//             auto cur = pq.top();
//             pq.pop();
//             res.push_back(cur.first);
//         }
        
//         sort(res.begin(), res.end());
//         return res;
//     }
    
    // O(n) + O(k)
    // take the binary search to find
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        deque<int> dq;
        int m = 0;
        for (int i = 0; i < arr.size(); i++)
            if (abs(arr[i]-x) < abs(arr[m]-x))
                m = i;
        
        int l = m, r = m+1;
        while (k--) {
            if (l < 0) dq.push_back(arr[r++]);
            else if (r >= arr.size()) dq.push_front(arr[l--]);
            else if (abs(arr[l]-x) <= abs(arr[r]-x)) dq.push_front(arr[l--]);
            else dq.push_back(arr[r++]);
        }
        return vector<int>(dq.begin(), dq.end());
    }
    
};
