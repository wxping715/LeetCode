class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(n < 1) return false;
        
        int m = matrix[0].size();
        if(m < 1) return false;
        
        int f = 0, r = n*m-1, mid;
        while(f <= r){
            mid = (f+r)/2;
            int val = matrix[mid/m][mid-m*(mid/m)];
            
            if(val == target) return true;
            else if(val < target) f = mid + 1;
            else r = mid - 1;
        }
        return false;
    }
};
