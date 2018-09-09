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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        unordered_map<int, int> count;
        ListNode* node = head;
        while (node) {
            if (count.find(node->val) != count.end()) count.at(node->val) += 1;
            else count.insert(make_pair(node->val, 1));
            node = node->next;
        }
        node = head;
        ListNode* prev = new ListNode(0);
        ListNode* newHead = prev;
        while (node) {
            //cout << node->val << " before while" << endl;
            while (node && count.at(node->val) > 1) node = node->next;
            //cout << node->val << " after while" << endl;
            prev->next = node;
            prev = prev->next;
            if (!node) break;
            node = node->next;
        }
        return newHead->next;
    }
};