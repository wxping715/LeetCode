/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        return build(nums, l, r);
    }
    
    TreeNode* build(vector<int>& nums, int l, int r) {
        if (l > r) return NULL;
        int m = (l+r)/2;
        
        TreeNode* cur = new TreeNode(nums[m]);
        cur->left = build(nums, l, m-1);
        cur->right = build(nums, m+1, r);
        return cur;
    }
};
