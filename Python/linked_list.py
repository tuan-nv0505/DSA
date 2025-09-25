from typing import Optional


class Node:
    def __init__(self, key):
        self.key = key
        self.next: Optional[Node] = None
        
class LinkedList:
    def __init__(self):
        self.head = None

    def insert_last(self, key):
        if self.head is None:
            self.head = Node(key)
        else:
            tmp = self.head
            while tmp.next is not None:
                tmp = tmp.next
            tmp.next = Node(key) # type: ignore

    def insert_first(self, key):
        if self.head is None:
            self.head = Node(key)
        else:
            new_node_first = Node(key)
            new_node_first.next = self.head
            self.head = new_node_first

    def remove_last(self):
        if self.head is None:
            return
        elif self.head.next is None:
            self.head = None
        else:
            tmp = self.head
            while tmp.next.next is not None:   #type:ignore
                tmp = tmp.next   #type:ignore
            tmp.next = None  #type:ignore

    def remove_first(self):
        if self.head is None:
            return
        elif self.head.next is None:
            self.head = None
        else:
            tmp = self.head
            while tmp.next.next is not None:  #type:ignore
                tmp = tmp.next  #type:ignore
            tmp.next = None   #type:ignore

    def find_node_first(self, key):
        tmp = self.head
        while tmp is not None and tmp.key != key:
            tmp = tmp.next
        return tmp

    def find_node_last(self, key):
        tmp = self.head
        res = None
        while tmp is not None:
            if tmp.key == key:
                res = tmp
            tmp = tmp.next
        return res

    def find_all(self, key):
        tmp = self.head
        nodes = []
        while tmp is not None:
            if tmp.key == key:
                nodes.append(tmp)
            tmp = tmp.next
        return nodes


    def show(self):
        tmp = self.head
        while tmp is not None:
            print(tmp.key, end=' ')
            tmp = tmp.next
        print()

if __name__ == "__main__":
   pass

    
    
            
