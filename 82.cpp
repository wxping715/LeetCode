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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        
        ListNode *pre = NULL, *cur = head, *res = NULL, *p;
        while (cur != NULL) {
            if (cur->next == NULL || cur->next->val != cur->val) {
                if (res == NULL) res = pre = cur;
                else {
                    pre->next = cur;
                    pre = cur;
                }
                cur = cur->next;
                
            } else {
                int curv = cur->val;
                p = cur->next;
                while (p != NULL && p->val == curv) p = p->next;
                cur = p;   
            }
        }
        
        if (pre == NULL) return NULL;
        pre->next = NULL;
        return res;
    }
};
