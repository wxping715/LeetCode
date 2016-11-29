/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode*, RandomListNode*> listMap;
        RandomListNode *rhead = NULL, *rear = NULL, *p = head;
        while (p != NULL) {
            RandomListNode* node = new RandomListNode(p->label);
            node->label = p->label;
            
            if (rear == NULL) {
                rhead = node;
                rear = node;
            } else {
                rear->next = node;
                rear = node;
            }
            listMap[p] = node;
            p = p->next;
        }
        
        p = head;
        RandomListNode *q = rhead;
        while (p != NULL) {
            if (p->random == NULL) q->random = NULL;
            else q->random = listMap[p->random];
            
            p = p->next;
            q = q->next;
        }
        return rhead;
    }
};
