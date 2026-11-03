from __future__ import annotations


class Node:
    def __init__(self, in_val: int, in_next: Node = None):
        self.val = in_val
        self.next = in_next


class MyLinkedList(Node):

    def __init__(self):
        self.head = None
        self.size = 0

    def get(self, index: int) -> int:
        if(self.size == 0 or index >= self.size):
            return -1
        cur: Node = self.head
        cnt: int  =  0
        while(cnt < index):
            cur = cur.next
            cnt += 1

        return cur.val

    def addAtHead(self, val: int) -> None:
        newnode: Node = Node(val, self.head)
        self.head = newnode
        self.size += 1
                

    def addAtTail(self, val: int) -> None:
        if(self.size == 0):
            return self.addAtHead(val)
        
        newnode: Node = Node(val)
        cur: Node = self.head
        prev: Node = cur
        while(cur is not None):
            prev = cur
            cur = cur.next

        prev.next = newnode                
        self.size += 1
        

    def addAtIndex(self, index: int, val: int) -> None:
        if(self.size < index): 
            return 

        if(index == 0): 
            return self.addAtHead(val)

        newnode: Node = Node(val)
        cnt: int = 0 
        cur: Node = self.head
        prev: Node = cur
        while(cnt < index):
            cnt += 1
            prev = cur
            cur = cur.next

        newnode.next = prev.next
        prev.next = newnode
        self.size += 1 
                

    def deleteAtIndex(self, index: int) -> None:
        if(index < 0 or index >= self.size): return

        if(index == 0):
            self.head = self.head.next
            self.size -= 1
            return 

        cnt: int = 0
        cur: Node = self.head
        prev: Node = cur
        while(cnt < index):
            cnt += 1
            prev = cur
            cur = cur.next

        prev.next = cur.next
        self.size -= 1


def printll(obj: MyLinkedList):
    if(obj.size == 0):
        print("EMPTY LINKED LIST")
        return 
    
    cur: Node = obj.head
    while(cur is not None):
        print(cur.val, end=" ")
        cur = cur.next
    print("")

def main():

    obj = MyLinkedList()
    
    obj.addAtHead(1)
    printll(obj)

    obj.deleteAtIndex(0)
    printll(obj)

    obj.addAtTail(2)
    printll(obj)
    
    d = obj.get(0)
    print(d)


    

if __name__ == "__main__":
    main()