/*
Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.

Example 1:
Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9

Output: True
Example 2:
Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28

Output: False
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
    
    TreeNode* next(stack<TreeNode*>& s, TreeNode* &cur, bool inc) {
        while (cur) {
            s.push(cur);
            cur = inc ? cur->left : cur->right;
        }
        
        TreeNode* npt = s.top();
        s.pop();
        
        cur = inc ? npt->right : npt->left;
        return npt;
    }
    
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        
        stack<TreeNode*> ls, rs;
        TreeNode *icur = root, *dcur = root;
        TreeNode *p = next(ls, icur, true), *q = next(rs, dcur, false);
        
        while (p->val != q->val) {
            if (p->val + q->val == k) return true;
            else if (p->val + q->val < k) {
                // move p
                p = next(ls, icur, true);
            }
            else {
                // move q
                q = next(rs, dcur, false);
            }
        }
        return false;
    }
};

class Solution {
    public boolean findTarget(TreeNode root, int k) {
        Set<Integer> hashset = new HashSet<>();
        return find(root, k, hashset);
    }
    
    private boolean find(TreeNode root, int k, Set<Integer> hashset) {
        if (root == null) return false;
        if (hashset.contains(k - root.val)) return true;
        hashset.add(root.val);
        
        return find(root.left, k, hashset) || find(root.right, k, hashset);
    }
}
