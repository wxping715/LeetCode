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
    /*
    * recursion method, notice:
    *   1. the return type is vector<TreeNode*>, so the TreeNode* variable should be created by molloc
    *   2. when calculating the cross set of lnode and nnode, we should consider the situation one of them is null rather than.
    *      using two for cycle briefly.
    */
    vector<TreeNode*> generateTrees(int n) {
        vector<int> nums;
        for (int i = 1; i <= n;i++) {
            nums.push_back(i);
        }
        return generateTree(nums);
    }
    
    vector<TreeNode*> generateTree(vector<int> nums) {
        if (nums.size() == 1) 
            return vector<TreeNode *>(1, generateNode(NULL, NULL, nums[0]));
        
        vector<TreeNode *> res;
        for (int i = 0; i < nums.size();i++) {
            vector<TreeNode *> lnode = generateTree(vector<int>(nums.begin(), nums.begin()+i));
            vector<TreeNode *> nnode = generateTree(vector<int>(nums.begin()+i+1, nums.end()));
            
            if (lnode.size() == 0) {
                for (int k = 0; k < nnode.size(); k++) 
                    res.push_back(generateNode(NULL, nnode[k], nums[i]));
            } else if (nnode.size() == 0) {
                for (int j = 0; j < lnode.size(); j++)
                    res.push_back(generateNode(lnode[j], NULL, nums[i]));
            } else {
                for (int j = 0; j < lnode.size(); j++) {
                    for (int k = 0; k < nnode.size(); k++) {
                        res.push_back(generateNode(lnode[j], nnode[k], nums[i]));
                    }
                }
            }
        }
        return res;
    }
    
    TreeNode* generateNode(TreeNode* left, TreeNode* right, int val) {
        TreeNode* node = (TreeNode *)malloc(sizeof(TreeNode));
        node->left = left;
        node->right = right;
        node->val = val;
        return node;
    }
};
