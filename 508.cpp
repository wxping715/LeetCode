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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int> freq;
        vector<int> res;
        
        if (!root) return res;
        
        dfs(root, freq);
        int maxf = INT_MIN;
        for (auto it = freq.begin(); it != freq.end(); it++) {
            if (it->second > maxf) {
                res.clear();
                maxf = it->second;
                res.push_back(it->first);
            } else if (it->second == maxf)
                res.push_back(it->first);
        }
        return res;
    }
    
    int dfs(TreeNode* root, unordered_map<int,int>& freq) {
        if (!root) return 0;
        
        int sum = dfs(root->left, freq) + dfs(root->right, freq) + root->val;
        freq[sum]++;
        return sum;
    }
};
