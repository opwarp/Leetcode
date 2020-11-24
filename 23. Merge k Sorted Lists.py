23. Merge k Sorted Lists.py
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution(object):
    def merge2Lists(self, l1, l2):
        head = None
        if l1 == None:
            return l2
        if l2 == None:
            return l1
        if l1.val > l2.val:
            head = l2
            head.next = self.merge2Lists(l1, l2.next)
        else:
            head = l1
            head.next = self.merge2Lists(l1.next, l2)
        return head
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        l = len(lists)
        if(l == 0):
            return None
        if(l == 1):
            return lists[0]
        l1 = self.mergeKLists(lists[:l/2])
        l2 = self.mergeKLists(lists[l/2:])
        return self.merge2Lists(l1, l2)