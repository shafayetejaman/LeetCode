#
# @lc app=leetcode id=328 lang=python3
#
# [328] Odd Even Linked List
#
from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


# @lc code=start
class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next or not head.next.next:
            return head

        head2 = head.next
        p1, p2 = head, head2

        while p1.next and p2.next:
            p1.next = p2.next
            p1 = p1.next
            p2.next = p1.next
            p2 = p2.next
        p1.next = head2
        return head


# @lc code=end
