#
# @lc app=leetcode id=160 lang=python
#
# [160] Intersection of Two Linked Lists
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """

        a, b = headA, headB
        a_len, b_len = 0, 0

        while a:
            a = a.next
            a_len += 1

        while b:
            b = b.next
            b_len += 1

        a, b = headA, headB
        
        while a_len > b_len:
            a_len -= 1
            a= a.next
            
        while b_len > a_len:
            b_len -= 1
            b= b.next
            
        while a and b:
            if a == b:
                return a
            a=a.next
            b=b.next

        return None


# @lc code=end
