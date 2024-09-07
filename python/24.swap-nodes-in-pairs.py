#
# @lc app=leetcode id=24 lang=python
#
# [24] Swap Nodes in Pairs
#


# @lc code=start
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution(object):

    def swapPairs(self, head: ListNode):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        dummy = ListNode(0, head)
        p=dummy

        while p.next and p.next.next:
            i = p.next
            j = p.next.next

            i.next = j.next
            j.next = i
            p.next = j

            p = i

        return dummy.next


# @lc code=end
