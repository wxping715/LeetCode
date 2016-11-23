class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0, number1, number2;
        for (int n: nums) {
            if (n == number1)
                cnt1++;
            else if (n == number2)
                cnt2++;
            else if (cnt1 == 0) {
                number1 = n;
                cnt1++;
            } 
            else if (cnt2 == 0) {
                number2 = n;
                cnt2++;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }
        
        cnt1 = 0;
        cnt2 = 0;
        for (int n : nums) {
            if (n == number1) cnt1++;
            else if (n == number2) cnt2++;
        }
        
        vector<int> res;
        if (cnt1 > nums.size()/3) res.push_back(number1);
        if (cnt2 > nums.size()/3) res.push_back(number2);
        
        return res;
    }
};
