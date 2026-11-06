


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def oddEvenList(self, head: ListNode | None) -> ListNode | None:
        if(head is None or head.next is None or head.next.next is None):
            return head

        odd: ListNode = head
        even: ListNode = head.next
        cur: ListNode = head.next.next
        link: ListNode = even
        retHead: ListNode = odd

        index: int = 1
        while(cur is not None):

            if (index % 2 == 0):
                even.next = cur
                even = even.next
            else:
                odd.next = cur
                odd = odd.next

            index += 1
            cur = cur.next

        odd.next = link
        even.next = None
        return retHead
                



        