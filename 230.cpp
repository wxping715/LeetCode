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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* stack[1000];
        int cnt = 0, top = 0;
        while(cnt < k) {
            if (root != NULL) {
                stack[top++] = root;
                root = root->left;
            } else {
                root = stack[--top];
                cnt++;
                root = root->right; 
            }
        }
        return stack[top]->val;
    }
};
