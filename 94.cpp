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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<struct TreeNode *> s;
        struct TreeNode *p = root;
        vector<int> v;
    
        while(p != NULL || !s.empty()){
            while(p != NULL){
                s.push(p);
                p = p->left;
            }
            
            if(!s.empty()){
                p = s.top();
                v.push_back(p->val);
                s.pop();
                p=p->right;
            }
        }
        
        return v;
    }
};
