# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if (l1 == None or l2 == None):
            if (l1 == None):
                return l2
            else:
                return l1
        if (l1.val >= l2.val):
            node = ListNode(l2.val)
            l2 = l2.next
        else:
            node = ListNode(l1.val)
            l1 = l1.next
        startNode = node
        while (l1 != None and l2 != None):
            if (l1.val >= l2.val):
                node.next = ListNode(l2.val)
                l2 = l2.next
            else:
                node.next = ListNode(l1.val)
                l1 = l1.next
            node = node.next
        if (l1 == None):
            node.next = l2
        if (l2 == None):
            node.next = l1
        return startNode