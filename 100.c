/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode *p, struct TreeNode *q) {
    
    if(p == NULL && q == NULL) return true;
    if(p != NULL && q != NULL){

        if(p->val != q->val) return false;
        if(!isSameTree(p->left,q->left)) return false;
        if(!isSameTree(p->right,q->right)) return false;
        
        return true;
    }
    return false;
}