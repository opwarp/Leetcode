19. Remove Nth Node From End of List.py
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# class Solution:
#     def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
#         nodes = []
#         while head:
#             nodes.append(head)
#             head = head.next
#         print(len(nodes))
#         if len(nodes) <= 1:
#             return None
#         if len(nodes) == n:
#             return nodes[1]
#         nodes[len(nodes)-n-1].next = nodes[len(nodes)-n].next
#         return nodes[0]

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        ahead = behind = head
        for _ in range(n):
            ahead = ahead.next
        if not ahead:
            return head.next
        while ahead.next:
            behind = behind.next
            ahead = ahead.next
        behind.next = behind.next.next
        return head