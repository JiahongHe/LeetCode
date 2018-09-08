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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        stack<ListNode*> s;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* node = dummy->next;
        ListNode* prev = dummy;
        while (node) {
            if (!node->next) return dummy->next;
            ListNode* nextStart = node->next->next;
            ListNode* node1 = node->next;
            ListNode* node2 = node;
            node1->next = node2;
            prev->next = node1;
            node2->next = nextStart;
            prev = node2;
            node = nextStart;
        }
        return dummy->next;
    }
};