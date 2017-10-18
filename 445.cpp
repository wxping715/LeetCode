/*
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    // stack version
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode*> s1, s2;
        int carry = 0;
        ListNode* head = NULL, *p;
        
        p = l1;
        while (p) {
            s1.push(p);
            p = p->next;
        }
        
        p = l2;
        while (p) {
            s2.push(p);
            p = p->next;
        }
        
        while (!s1.empty() || !s2.empty() || carry != 0) {
            if (!s1.empty()) {
                carry += s1.top()->val;
                s1.pop();
            }
            
            if (!s2.empty()) {
                carry += s2.top()->val;
                s2.pop();
            }
            
            ListNode* node = new ListNode(carry%10);
            node->next = head;
            head = node;
            
            carry = carry/10;
        }
        return head;
    }
    
    // reverse version
};
