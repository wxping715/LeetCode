class Solution {
public:
    int majorityElement(vector<int> &num) {
        sort(num.begin(),num.end());
        return num[num.size()/2];
    }
};