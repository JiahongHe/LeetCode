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
        RandomListNode * cur = head;
        while (cur) {
            RandomListNode * tmp = cur->next;
            cur->next = new RandomListNode(cur->label);
            cur->next->next = tmp;
            cur = cur->next->next;
        }
        cur = head;
        while (cur) {
            if (cur->random) cur->next->random = cur->random->next;
            cur = cur->next->next;
        }
        RandomListNode * cur_cp = new RandomListNode(0);
        RandomListNode * head_cp = cur_cp;
        cur = head;
        while (cur) {
            cur_cp->next = cur->next;
            cur->next = cur->next->next;
            cur = cur->next;
            cur_cp = cur_cp->next;
        }
        return head_cp->next;
    }
};