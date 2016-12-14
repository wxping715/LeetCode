/*Given a non-negative number represented as a singly linked list of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.

Example:
Input:
1->2->3

Output:
1->2->4
Show Company Tags
Show Tags
Show Similar Problems*/


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
    ListNode* plusOne(ListNode* head) {
        if (head == NULL) return head;
        
        ListNode* rhead = reverse(head);
        // print(rhead);
        rhead->val += 1;
        
        int carry = 0;
        ListNode *p = rhead;
        while (p != NULL) {
            int temp = carry;
            carry = (p->val + carry)/10;
            p->val = (p->val+temp)%10;
            p = p->next;
            if (carry == 0) break;
        }
        
        ListNode *nhead = reverse(rhead);
        if (carry != 0) {
            ListNode *anode = new ListNode(carry);
            anode->next = nhead;
            nhead = anode;
        }
        return nhead;
    }
    
    ListNode *reverse(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *nhead = NULL, *p = head, *q;
        while (p != NULL) {
            q = p->next;
            p->next = nhead;
            nhead = p;
            p = q;
        }
        return nhead;
    }
};
