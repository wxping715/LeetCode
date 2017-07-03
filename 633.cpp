class Solution {
public:
    
//     // O(sqrt(n)) time, O(sqrt(n)) space
//     bool judgeSquareSum(int c) {
//         int x = (int)sqrt(c);
//         unordered_set<int> hashtable;
        
//         for (int i = 0; i <= x; i++)
//             hashtable.insert(i*i);
        
//         for (int i = 0; i <= x; i++)
//             if (hashtable.count(c-i*i))
//                 return true;
//         return false;
//     }
    
    // // O(sqrt(n)) time, constant
    bool judgeSquareSum(int c) {
        int x = (int)sqrt(c);
        int i = 0, j = x;
        while (i <= j) {
            int t = i*i + j*j;
            if (t == c) return true;
            else if (t < c) i++;
            else j--;
        }
        return false;
    }
};
