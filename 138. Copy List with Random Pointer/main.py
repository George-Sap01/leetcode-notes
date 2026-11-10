
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random


class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if head is None:
            return None

        dummy: Node = Node(0)
        cur: Node = dummy
        new_old_hash = {}

        while (head is not None):
            newnode = Node(head.val, head.next, head.random)
            new_old_hash[head] = newnode
            head = head.next
            cur.next = newnode
            cur = cur.next
        
        cur = dummy.next
        while(cur is not None):
            if cur.random is not None:
                cur.random = new_old_hash[cur.random]
            cur = cur.next                 

        return dummy.next
        