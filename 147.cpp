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
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        
        ListNode *res = NULL, *pre = NULL, *cur = head, *r = head->next, *p;
        while (cur != NULL) {
            pre = NULL; p = res;
            while (p != NULL && p->val < cur->val) {
                pre = p;
                p = p->next;
            }
            if (pre == NULL) {
                cur->next = res;
                res = cur;
            } else {
                pre->next = cur;
                cur->next = p;
            }
            cur = r;
            if (r != NULL) r = r->next;
        }
        return res;
    }
};
