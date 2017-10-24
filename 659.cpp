/*
You are given an integer array sorted in ascending order (may contain duplicates), you need to split them into several subsequences, where each subsequences consist of at least 3 consecutive integers. Return whether you can make such a split.

Example 1:
Input: [1,2,3,3,4,5]
Output: True
Explanation:
You can split them into two consecutive subsequences : 
1, 2, 3
3, 4, 5
Example 2:
Input: [1,2,3,3,4,4,5,5]
Output: True
Explanation:
You can split them into two consecutive subsequences : 
1, 2, 3, 4, 5
3, 4, 5
Example 3:
Input: [1,2,3,4,4,5]
Output: False
Note:
The length of the input is in range of [1, 10000]
*/

class Solution {
public:
    
    // O(n) sapce, O(n) time
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> hashmap, needmap;
        for (int num : nums)
            hashmap[num]++;
        
        for (int num : nums) {
            cout << num << " " << hashmap[num] << " " << needmap[num] << endl;
            if (hashmap[num] == 0) continue;
            
            // can push to the end of a consecutive array
            if (needmap[num] > 0) {
                needmap[num]--;
                needmap[num+1]++;
            }
            else if (hashmap[num+1] > 0 && hashmap[num+2] > 0) {
                hashmap[num+1]--;
                hashmap[num+2]--;
                needmap[num+3]++;
            }
            else return false;
            hashmap[num]--;
        }
        return true;
    }
};
