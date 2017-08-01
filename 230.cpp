/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ? k ? BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
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

/*
follow up: add a field for every node which is the number smaller than it

*/

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        TreeNode* p = root;
        
        int cnt = 0;
        while (p || !s.empty()) {
            while (p) {
                s.push(p);
                p = p->left;
            }
            
            if (!s.empty()) {
                p = s.top();
                s.pop();
                
                cnt++;
                if (cnt == k)
                    return p->val;
                p = p->right;
            }
        }
    }
};
