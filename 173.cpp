/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        dfs(root);
        it = values.begin();
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return it != values.end();
    }

    /** @return the next smallest number */
    int next() {
        return *(it++);
    }
    
    void dfs(TreeNode* node) {
        if (node == NULL) return;
        
        dfs(node->left);
        values.push_back(node->val);
        dfs(node->right);
    }

private:
    vector<int> values; 
    vector<int>::iterator it;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
