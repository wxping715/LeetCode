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
    /*
    * 1. find the mid item
    * 2. revert the last part
    * 3. compare the previous and last part, record the result
    * 4. revert the last part to restore
    */
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) return true;
        
        ListNode *mid = head, *q = head, *p;
        while (q->next != NULL) {
            if (q->next->next == NULL)
                break;
            q = q->next->next;
            mid = mid->next;
        }
        
        ListNode *rhead = revert(mid->next);
        mid->next = NULL;
        
        p = head; q = rhead;
        bool res = true;
        while (q != NULL) {
            if (p->val != q->val) {
                res = false;
                break;
            }
            p = p->next;
            q = q->next;
        }
        mid->next = revert(rhead);
        return res;
    }
    
    ListNode* revert(ListNode* head) {
        ListNode *p = NULL, *q = head;
        while (q != NULL) {
            ListNode* t = q->next;
            q->next = p;
            p = q;
            q = t;
        }
        return p;
    }
};
