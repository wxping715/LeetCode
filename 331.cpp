/*
One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as #.

     _9_
    /   \
   3     2
  / \   / \
 4   1  #  6
/ \ / \   / \
# # # #   # #
For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.

Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.

Each comma separated value in the string must be either an integer or a character '#' representing null pointer.

You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".

Example 1:
"9,3,4,#,#,1,#,#,2,#,6,#,#"
Return true

Example 2:
"1,#"
Return false

Example 3:
"9,#,#,1"
Return false

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.
*/

class Solution {
public:
    
    //stack version
    bool isValidSerialization(string preorder) {
        stack<string> st;
        
        istringstream is(preorder);
        string token;
        while (getline(is, token, ',')) {
            while (token == "#" && !st.empty() && st.top() == token) {
                st.pop();
                if (st.empty()) return false;
                st.pop();
            }
            st.push(token);
        }
        
        return st.size() == 1 && st.top() == "#";
    }
    
    //degree version
    bool isValidSerialization(string preorder) {
        istringstream is(preorder);
        string token;
        
        int degree = -1;
        while (getline(is, token, ',')) {
            degree++;
            if (degree > 0) return false;
            if (token != "#") degree -= 2;
        }
        return degree == 0;
    }
};
