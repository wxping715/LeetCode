/*
Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:

The root is the maximum number in the array.
The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.
Construct the maximum tree by the given array and output the root node of this tree.

Example 1:
Input: [3,2,1,6,0,5]
Output: return the tree root node representing the following tree:

      6
    /   \
   3     5
    \    / 
     2  0   
       \
        1
Note:
The size of the given array will be in the range [1,1000].
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    // NlogN
//     TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
//         if (nums.empty()) return NULL;
//         return build(nums, 0, nums.size()-1);
//     }
    
//     TreeNode* build(vector<int>& nums, int l, int r) {
//         if (l > r) return NULL;
        
//         int maxi = l;
//         for (int i = l; i <= r; i++)
//             if (nums[maxi] < nums[i])
//                 maxi = i;
//         TreeNode* root = new TreeNode(nums[maxi]);
//         root->left = build(nums, l, maxi-1);
//         root->right = build(nums, maxi+1, r);
//         return root;
//     }
    
    // O(N) -- really smart
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<TreeNode*> s;
        for (int num : nums) {
            TreeNode* cur = new TreeNode(num);
            while (!s.empty() && s.back()->val < num) {
                cur->left = s.back();
                s.pop_back();
            }
            if (!s.empty()) 
                s.back()->right = cur;
            s.push_back(cur);
        }
        return s.front();
    }
    
};
