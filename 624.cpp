class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int minv1 = INT_MAX, minv2 = INT_MAX, mini1, mini2;
        int maxv1 = INT_MIN, maxv2 = INT_MIN, maxi1, maxi2;
        
        for (int i = 0; i < arrays.size(); i++) {
            if (arrays[i].front() < minv1) {
                minv2 = minv1;
                mini2 = mini1;
                minv1 = arrays[i].front();
                mini1 = i;
            } else if (arrays[i].front() < minv2) {
                minv2 = arrays[i].front();
                mini2 = i;
            }
            
            if (arrays[i].back() > maxv1) {
                maxv2 = maxv1;
                maxi2 = maxi1;
                maxv1 = arrays[i].back();
                maxi1 = i;
            } else if (arrays[i].back() > maxv2) {
                maxv2 = arrays[i].back();
                maxi2 = i;
            }
        }
        
        if (maxi1 != mini1) return maxv1 - minv1;
        else return max(maxv2-minv1, maxv1-minv2);
    }
};
