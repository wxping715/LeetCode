/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> nums;
        preorder(root, nums);
        string res = "";
        for (int i = 0; i < nums.size(); i++) {
            if (i != 0) res.push_back(',');
            res += nums[i];
        }
        return res;
    }
    
    void preorder(TreeNode* root, vector<string>& nums) {
        if (root == NULL) return;
        nums.push_back(to_string(root->val));
        preorder(root->left, nums);
        preorder(root->right, nums);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "") return NULL;
        vector<int> nums;
        int num = 0;
        for (int i = 0; i < data.length(); i++) {
            while (i < data.length() && data[i] != ',') {
                num = num*10 + data[i]-'0';
                i++;
            }
            nums.push_back(num);
            num = 0;
        }
        return build(nums, 0, nums.size()-1);
    }
    
    TreeNode* build(vector<int> nums, int l, int r) {
        if (l > r) return NULL;
        TreeNode* node = new TreeNode(nums[l]);
        int mid = l+1;
        while (mid <= r && nums[mid] < nums[l])
            mid++;
        node->left = build(nums, l+1, mid-1);
        node->right = build(nums, mid, r);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
