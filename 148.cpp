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
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode*p1 = head, *p2 = head;
        while (p1->next != NULL && p1->next->next != NULL) {
            p1 = p1->next->next;
            p2 = p2->next;
        }
        
        p1 = p2;
        p2 = p2->next;
        p1->next = NULL;
        p1 = sortList(head);
        p2 = sortList(p2);
        return merge(p1, p2);
    }
    
    ListNode* merge(ListNode* l1, ListNode *l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        
        ListNode* nhead = NULL, *rear = NULL;
        if (l1->val < l2->val) {
            nhead = l1; l1 = l1->next;
        } else { nhead = l2; l2 = l2->next;}
        rear = nhead;
        
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                rear->next = l1;
                l1 = l1->next;
            } else {
                rear->next = l2;
                l2 = l2->next;
            }
            rear = rear->next;
        }
        if (l1 != NULL) rear->next = l1;
        else if (l2 != NULL) rear->next = l2;
        return nhead;
    }
};
