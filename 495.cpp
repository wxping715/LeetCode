class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int s = -1, e = -1, res = 0;
        for (int t : timeSeries) {
            if (t > e) {
                res += (e == -1 ? 0 : e - s + 1);
                s = t;
                e = t + duration - 1;
            }
            else e = t + duration - 1;
        }
        if (e != -1) res += e - s + 1;
        return res;
    }
};
