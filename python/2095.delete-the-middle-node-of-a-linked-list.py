#
# @lc app=leetcode id=2095 lang=python3
#
# [2095] Delete the Middle Node of a Linked List
#


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


from typing import Optional

# @lc code=start


# class Solution:
#     def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
#         n = 0
#         p = head

#         while p:
#             n += 1
#             p = p.next

#         if n == 1:
#             return None
#         p = head

#         for i in range(n // 2 - 1):
#             p = p.next

#         p.next = p.next.next

#         return head


class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head and not head.next:
            return None

        fast = slow = head
        prev = None

        while fast and fast.next:
            fast = fast.next.next
            prev = slow 
            slow = slow.next
            
        prev.next = prev.next.next 
            
        return head


# @lc code=end
