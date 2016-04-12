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
    * 1. split the linked list into odd list and even list
    * 2. concat them
    */
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        
        ListNode *odd, *oddr=NULL, *even, *evenr=NULL;
        ListNode *p = head;
        bool isodd = true;
        
        while (p != NULL) {
            if (isodd) {
                if (oddr == NULL) {
                    odd = p;
                    oddr = p;
                } else {
                    oddr->next = p;
                    oddr = p;   
                }
            } else {
                if (evenr == NULL) {
                    even = p;
                    evenr = p;
                } else {
                    evenr->next = p;
                    evenr = p;
                }
            }
            isodd = !isodd;
            p = p->next;
        }
        
        evenr->next = NULL;
        oddr->next = even;
        return odd;
    }
};
