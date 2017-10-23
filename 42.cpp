/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!


*/

class Solution {
public:
    
    // stack version
    int trap(vector<int>& height) {
        stack<int> st;
        int water = 0;
        
        for (int i = 0; i < height.size(); i++) {
            // can take water
            if (!st.empty() && height[i] > height[st.top()]) {
                int bottom = height[st.top()];
                st.pop();
                while (!st.empty() && height[st.top()] <= height[i]) {
                    water += (height[st.top()]-bottom) * (i - st.top() - 1);
                    bottom = height[st.top()];
                    st.pop();
                }
                
                if (!st.empty()) water += (height[i] - bottom) * (i - st.top()-1);
            }
            st.push(i);
        }
        return water;
    }
    
    // two pointers
    int trap(vector<int>& height) {
        vector<int> rightMax(height.size(), 0);
        int maxv = 0;
        for (int i = (int)height.size() - 1; i >= 0; i--) {
            rightMax[i] = maxv;
            maxv = max(maxv, height[i]);
        }
        
        int water = 0;
        maxv = 0;
        for (int i = 0; i < height.size(); i++) {
            int hmin = min(maxv, rightMax[i]);
            water += hmin <= height[i] ? 0 : hmin - height[i];
            maxv = max(maxv, height[i]);
        }
        return water;
    }
};
