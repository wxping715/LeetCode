/*Given a sorted array of integers nums and integer values a, b and c. Apply a function of the form f(x) = ax2 + bx + c to each element x in the array.

The returned array must be in sorted order.

Expected time complexity: O(n)

Example:
nums = [-4, -2, 2, 4], a = 1, b = 3, c = 5,

Result: [3, 9, 15, 33]

nums = [-4, -2, 2, 4], a = -1, b = 3, c = 5

Result: [-23, -5, 1, 7]
Credits:
Special thanks to @elmirap for adding this problem and creating all test cases.*/

class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        vector<int> res;
        if (nums.empty()) return res;
        
        int midx = 0, flag;
        if (a == 0 && b < 0) midx = nums.size()-1;
        else if (a != 0){
            double x = -1.0*b/(2*a);
            flag = a > 0 ? 1 : -1;
            for (int i = 0; i < nums.size(); i++)
                if (abs(nums[midx] - x) > abs(nums[i] - x))
                    midx = i;
        }
                    
        int i = midx, j = midx+1;
        while (i >= 0 && j < nums.size()) {
            int v1 = a*nums[i]*nums[i] + b*nums[i] + c;
            int v2 = a*nums[j]*nums[j] + b*nums[j] + c;
            if (v1*flag < v2*flag) {
                res.push_back(v1);
                i--;
            } else {
                res.push_back(v2);
                j++;
            }
        }
        while (i >= 0)  res.push_back(a*nums[i]*nums[i] + b*nums[i--] + c);
        while (j < nums.size()) res.push_back(a*nums[j]*nums[j] + b*nums[j++] + c);
        
        if (flag < 0) reverse(res.begin(), res.end());
        return res;
    }
};
