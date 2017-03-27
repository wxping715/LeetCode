class Solution {
public:
    vector<int> constructRectangle(int area) {
        int w = (int)sqrt(area);
        vector<int> res;
        while (w >= 1) {
            if (area%w == 0) {
                res.push_back(area/w);
                res.push_back(w);
                break;
            }
            w--;
        }
        return res;
    }
};
