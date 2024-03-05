class Node:

    def __init__(self, key, val) -> None:

        self.key, self.val = key, val
        self.next = self.prev = None


class LRUCache:

    def __init__(self, capacity: int):

        self.cap = capacity
        self.Map = {}
        self.left, self.right = Node(0, 0), Node(0, 0)
        self.left.next = self.right
        self.right.prev = self.left

    def insert(self, node):

        left = self.right.prev
        right = self.right

        left.next = node
        node.prev = left

        right.prev = node
        node.next = right

    def remove(self, node):

        prev = node.prev
        next = node.next

        prev.next = next
        next.prev = prev

    def get(self, key: int) -> int:

        if key in self.Map:
            node = self.Map[key]

            self.remove(node)
            self.insert(node)

            return node.val

        return -1

    def put(self, key: int, value: int) -> None:

        if key in self.Map:
            self.remove(self.Map[key])
        else:
            if self.cap == len(self.Map):
                self.Map.pop(self.left.next.key)
                self.remove(self.left.next)

        self.Map[key] = Node(key, value)
        self.insert(self.Map[key])


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


# 2130. Maximum Twin Sum of a Linked List
class Solution:

    def reverse_list(self, curr, prev=None):
        if not curr:
            return prev

        r = self.reverse_list(curr.next, curr)
        curr.next = prev
        return r

    def mid(self, head):
        fast = head
        slow = head
        prev = None

        while fast:
            fast = fast.next.next
            prev = slow
            slow = slow.next
        
        prev.next = None
        return slow

    def pairSum(self, head):
        n = 0
        p = head

        while p:
            p = p.next
            n += 1

        m = n // 2

        p = self.mid(head)

        rh = self.reverse_list(p)
        _sum = 0
        
        while rh:
            _sum = max(_sum, head.val+rh.val)
            head = head.next
            rh = rh.next
            
        return _sum
            
