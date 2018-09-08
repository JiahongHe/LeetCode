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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head || m == n) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* node = head;
        ListNode* prev = dummy;
        ListNode* nextNode;
        int index = 1;
        stack<ListNode*> s;
        while (node && index <= n) {
            ListNode* curNode = node;
            if (index >= m) s.push(curNode);
            else prev = node;
            node = node->next;
            index++;
        }
        nextNode = node;
        //cout << s.size() << " " << prev->val << " " <<  nextNode->val << endl;
        while (!s.empty()) {
            node = s.top();
            s.pop();
            prev->next = node;
            prev = prev->next;
        }
        node->next = nextNode;
        return dummy->next;
    }
};