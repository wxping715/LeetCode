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
    /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
struct TreeNode* dfs(struct TreeNode *root,struct TreeNode *& rear){
    
    if(root == NULL) return NULL;
    if(root->left == NULL && root->right == NULL){
        rear = root;
        return root;  
    } 
    
    struct TreeNode *left, *right, *lrear, *rrear, *p, *q;
    left = dfs(root->left,lrear);
    right = dfs(root->right,rrear);
    
    if(left == NULL){
        rear = rrear;
        root->left = NULL;
        root->right = right;
        return root;
    }else if(right == NULL){
        rear = lrear;
        root->right = left;
        root->left = NULL;
        return root;
    }else{
        p = right;
        rear = rrear;
        root->right = left;
        root->left = NULL;
        lrear->right = right;
        return root;
    }
}

void flatten(struct TreeNode* root) {
    struct TreeNode *rear = NULL;
    root = dfs(root,rear);
}

};
