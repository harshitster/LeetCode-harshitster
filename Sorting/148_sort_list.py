# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        temp = head
        h = []
        while temp:
            h.append((temp.val))
            temp = temp.next

        heapq.heapify(h)
        new_head = None
        prev = None

        while h:
            val = heapq.heappop(h)
            node = ListNode(val)
            if prev is None:
                new_head = node
            else:
                prev.next = node
            prev = node

        return new_head