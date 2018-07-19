class Solution:
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head is None:
            return head
        prev = head
        curr = head
        while (curr != None and curr.next != None):
            curr = curr.next
            if curr.val == prev.val:
                if (curr.next == None):
                    prev.next = None
                    return head
                else:
                    prev.next = curr.next
            else:
                prev = prev.next
        return head
                