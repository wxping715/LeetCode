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
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL || head->next == NULL) return head;
        
        ListNode *s = NULL, *sr=NULL, *g=NULL, *gr=NULL, *p = head;
        while(p != NULL) {
            if (p->val < x) {
                if (sr == NULL) s = sr = p;
                else {
                    sr->next = p;
                    sr = p;
                }
            } else {
                if (gr == NULL) g = gr = p;
                else {
                    gr->next = p;
                    gr = p;
                }
            }
            p = p->next;
        }
        
        if (s == NULL) {
            gr->next = NULL;
            return g;
        }
        if (g == NULL) {
            sr->next = NULL;
            return s;
        }
        
        gr->next = NULL;
        sr->next = g;
        return s;
    }
};
