/* Verify Preorder Sequence in Binary Search Tree   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 14526
Total Submissions: 37561
Difficulty: Medium
Contributors: Admin
Given an array of numbers, verify whether it is the correct preorder traversal sequence of a binary search tree.

You may assume each number in the sequence is unique.

Follow up:
Could you do it using only constant space complexity?*/

class Solution {
public:

    // O(nlogn)
    bool verifyPreorder(vector<int>& preorder) {
        if (preorder.size() == 0) return true;
        return verify(preorder, 0, preorder.size()-1);
    }
    
    bool verify(vector<int> &preorder, int l, int r) {
        if (l >= r) return true;
        int root = preorder[l], nl = l+1;
        
        while (nl <= r && preorder[nl] < root) nl++;
        for (int i = nl; i <= r; i++) 
            if (preorder[i] < root) return false;
    
        return verify(preorder, l+1, nl-1) && verify(preorder, nl, r);
    }
    
    
    // // O(n) space and O(n) time
    bool verifyPreorder(vector<int>& preorder) {
        int low = INT_MIN;
        stack<int> s;
        for (int p : preorder) {
            if (p < low) return false;
            while (!s.empty() && s.top() < p) {
                low = s.top();
                s.pop();
            }
            s.push(p);
        }
        return true;
    }
    
    // O(1) space and O(1) time
    bool verifyPreorder(vector<int>& preorder) { 
        int low = INT_MIN, top = -1;
        for (int p : preorder) {
            if (p < low) return false;
            while (top >= 0 && preorder[top] < p)
                low = preorder[top--];
            preorder[++top] = p;
        }
        return true;
    }
};
