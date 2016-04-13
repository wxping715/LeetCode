class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        for(int i = 0;i < matrix.size();i++){
            if(matrix[i].size() < 1) return false;
            if(target < matrix[i][0]) return false;
            if(bsearch(matrix[i],target)) return true;
        }
        return false;
    }
    
    bool bsearch(vector<int> v, int key){
        int f = 0, r = v.size() - 1,mid;
        while(f <= r){
            mid = f+(r-f)/2;
            if(v[mid] == key) return true;
            else if(v[mid] < key) f = mid + 1;
            else r = mid -1;
        }
        return false;
    }
};
