from typing import Optional

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        if(head is None or head.next is None):
            return False

        fast: ListNode = head
        slow: ListNode = head
        while(fast is not None and fast.next is not None):
            slow = slow.next
            fast = fast.next.next
            if(fast == slow):
                return True
        return False
            
    