class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p == NULL) return q;
        if (q == NULL) return p;
        if (root == NULL) return NULL;
        
        unordered_map<TreeNode*, TreeNode*> parent_map;
        dfs(root, NULL, parent_map);
        
        unordered_set<TreeNode *> p1;
        while (p != NULL) {
            p1.insert(p);
            p = parent_map[p];
        }
        
        while (q != NULL) {
            if (p1.find(q) != p1.end()) return q;
            q = parent_map[q];
        }
        return NULL;
    }
    
    void dfs(TreeNode* root, TreeNode *pre, unordered_map<TreeNode*, TreeNode*> &parent_map) {
        if (root == NULL) return;
        parent_map[root] = pre;
        pre = root;
        dfs(root->left, pre, parent_map);
        dfs(root->right, pre, parent_map);
    }
};
