

class Node:
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child


class Solution(object):
    def flatten(self, head):
        if head is None:
            return None
        
        curr = head
        while curr is not None:
            # if the current node has a child then flatten the child first
            if curr.child is not None:
                # 📌 STEP 1: Save the "after" part
                next_node = curr.next
                
                # 📌 STEP 2: Find where the child chain ends
                child_tail = curr.child
                while child_tail.next is not None:
                    child_tail = child_tail.next
                
                # 📌 STEP 3: Connect child tail to saved "after" part
                if next_node is not None:
                    child_tail.next = next_node
                    next_node.prev = child_tail
                
                # 📌 STEP 4: Connect current to child head
                curr.next = curr.child
                curr.child.prev = curr
                # Clean up!
                curr.child = None
            
            # move forward if the curr node has no child
            curr = curr.next
        
        return head