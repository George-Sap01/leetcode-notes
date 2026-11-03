from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        if headA == headB:
            return headA
        
        first: ListNode = headA
        second: ListNode = headB

        while(first is not None or second is not None):
            first = headB if first is None else first.next
            second = headA if second is None else second.next

            if(first == second):
                return first

        return None


        
        