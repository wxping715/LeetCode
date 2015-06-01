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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        queue< pair<TreeNode*,int> > q;
        vector<vector<int> > res;
        pair<TreeNode *,int> p;
        bool newrow = true;
        
        if(root == NULL) return res;
        
        q.push(make_pair(root,1));
        while(!q.empty()){
            p = q.front();
            q.pop();
            
            if(newrow == true){
                vector<int> v;
                v.push_back(p.first->val);
                res.push_back(v);
                newrow = false;
            }else{
                int ind = p.second-1;
                res[ind].push_back(p.first->val);
            }
            
            if(q.empty() || q.front().second != p.second) newrow = true;
            
            if(p.first->left != NULL) q.push(make_pair(p.first->left,p.second+1));
            if(p.first->right != NULL) q.push(make_pair(p.first->right,p.second+1));
        }
        
        vector<int> v;
        int len = res.size();
        for(int i = 0;i < len/2;i++){
            v = res[i];
            res[i] = res[len-1-i];
            res[len-1-i] = v;
        }
        
        return res;
    }
};
