/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL, *rear = NULL;
        ListNode *p1 = l1, *p2 = l2, *p;
        while (p1 || p2) {
            if (!p2 || (p1 && p1->val < p2->val)) {
                p = p1;
                p1 = p1->next;
            } else {
                p = p2;
                p2 = p2->next;
            }
            
            
            if (rear == NULL) head = p;
            else rear->next = p;
            
            rear = p;    
            p->next = NULL;
        }
        return head;
    }
};
