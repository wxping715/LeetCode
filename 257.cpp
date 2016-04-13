class Solution {
public:

    using Elem = pair<TreeNode*, string>;
    using Stack = stack<Elem>;

    vector<string> binaryTreePaths(TreeNode* root) {

        vector<string> paths;

        if(root)
        {
            Stack pool;
            pool.push(Elem(root, to_string(root->val)));

            while(!pool.empty())
            {
                auto p = pool.top();
                pool.pop();

                if(!p.first->left && !p.first->right)
                    paths.push_back(p.second);

                if(p.first->left)
                {
                    string nstring = p.second + "->" + to_string(p.first->left->val);
                    pool.push(Elem(p.first->left, nstring));
                }

                if(p.first->right)
                {
                    string nstring = p.second + "->" + to_string(p.first->right->val);
                    pool.push(Elem(p.first->right, nstring));
                }
            }
        }

        return paths;
    }
};
