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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<pair<struct TreeNode *, int> > s;
        struct TreeNode *p = root;
        pair<struct TreeNode *, int> tmp;
        vector<int> v;
        
        while(p != NULL || !s.empty()){
            while(p != NULL){
                tmp.first = p;
                tmp.second = 1;
                s.push(tmp);
                p=p->left;
            }
            
            if(!s.empty()){
                tmp = s.top();
                s.pop();
                
                if(tmp.second < 2){
                    tmp.second++;
                    s.push(tmp);
                    p = tmp.first->right;
                }else{
                    v.push_back(tmp.first->val);
                    p = NULL;
                }
            }
        }
        
        return v;
    }
};


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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<struct TreeNode *> s;
        struct TreeNode *p = root,*pre = NULL;
        vector<int> v;
        
        if(root == NULL) return v;
        
        s.push(root);
        while(!s.empty()){
            
            p = s.top();
            if((p->left==NULL&&p->right==NULL)||(pre!=NULL&&(pre==p->left||pre==p->right))){
                v.push_back(p->val);
                pre = p;
                s.pop();
            }else{
                if(p->right != NULL) s.push(p->right);
                if(p->left != NULL) s.push(p->left);
            }
        }
        
        return v;
    }
};
