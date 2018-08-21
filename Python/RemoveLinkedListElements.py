# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeElements(self, head, val):
        """
        :type head: ListNode
        :type val: int
        :rtype: ListNode
        """
        if not head:
            return None
        slow = head
        fast = head.next
        while slow.val == val:
            head = slow.next
            slow = slow.next
            if not fast:
                return head
            fast = fast.next
            
        while fast:
            if fast.val == val:
                if not fast.next:
                    slow.next = None
                    return head
                slow.next = fast.next
                fast = fast.next
            elif fast.next:
                slow = slow.next
                fast = fast.next
            else:
                return head
        return head