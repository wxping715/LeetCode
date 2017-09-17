/*
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
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
    
    // recursive method
    void flatten(TreeNode* root) {
        TreeNode* tail = flattenSub(root);
        tail = root;
    }
    
    TreeNode* flattenSub(TreeNode* root) {
        if (!root) return root;
        if (!root->left && !root->right) return root;
    
        TreeNode* ltail = flattenSub(root->left);
        TreeNode* rtail = flattenSub(root->right);
        if (!ltail) return rtail;
        else {
            ltail->right = root->right;
            root->right = root->left;
            root->left = NULL;
            if (rtail) return rtail;
            return ltail;
        }
    }
    
    // iterative solution
    // preorder
    void flatten(TreeNode* root) {
        TreeNode* rear = NULL;
        stack<TreeNode*> s;
        if (root) s.push(root);
        while (!s.empty()) {
            auto cur = s.top();
            s.pop();
            
            if (cur->right) s.push(cur->right);
            if (cur->left) s.push(cur->left);
            
            cur->left = NULL;
            cur->right = NULL;
            
            if (rear) {
                rear->right = cur;
                rear = cur;
            }
            else rear = cur;
        }
    }
};
