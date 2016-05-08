/*
* using the degree to check whether valid.
*   1. each node has a indegree
*   2. no-lead node has two outdegree
*   3. the final degree is 0
*/
class Solution {
public:
    bool isValidSerialization(string preorder) {
        //root has no degree
        int degree = -1;
        bool is = false;
        for (int i = 0;i < preorder.length(); i++) {
            if (preorder[i] == ',') continue;
            else if (preorder[i] == '#') is = true;
            else {
                is = false;
                while (i+1<preorder.length() && preorder[i+1] >= '0' && preorder[i+1] <= '9') i++;
            }
            
            degree++;
            if (degree > 0) return false;
            if (!is) degree -= 2;
        }
        return degree == 0;
    }
};


/*
* using stack top check, each time push the element into the stack.if stack[-1] and stack[-2] are '#', stack[-3] != '#', it means a valid node, then remove those nodes from stack and push the '#' to stack.
*/
class Solution {
public:
    vector<int> s;
    bool isValidSerialization(string preorder) {
        
        bool is = false;
        for (int i = 0;i < preorder.length(); i++) {
            if (preorder[i] == ',') continue;
            else if (preorder[i] == '#') is = true;
            else {
                is = false;
                while(i+1<preorder.length()&&preorder[i+1]>='0'&&preorder[i+1]<='9') i++;
            }
            s.push_back(is);
            while(s.size() >= 3) {
                if (s[s.size()-1] && s[s.size()-2] && !s[s.size()-3]) {
                    s.pop_back();
                    s.pop_back();
                    s.pop_back();
                    s.push_back(true);
                } else break;
            }
        }
        if (s.size() == 1 && s.front()) return true;
        return false;
    }
};
