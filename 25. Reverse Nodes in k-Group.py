# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        pregtail = head
        curgtail = head
        ghead = head
        if not ghead:
            return ghead
        head = None
        count = 1
        
        while True:
            curgtail = ghead
            while count < k and ghead and ghead.next:
                ghead = ghead.next
                count += 1
            ghead = curgtail
            if count == k:
                if not ghead:
                    break
                nxt = ghead.next
                while count > 1:
                    count -= 1
                    temp = nxt.next
                    nxt.next = ghead
                    ghead = nxt
                    nxt = temp
                if not head:
                    head = ghead
                else:
                    pregtail.next = ghead
                    pregtail = curgtail
                ghead = nxt
            else:
                if not head:
                    head = ghead
                    break
                pregtail.next = ghead
                break
        return head