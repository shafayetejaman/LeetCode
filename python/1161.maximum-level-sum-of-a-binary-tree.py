#
# @lc app=leetcode id=1161 lang=python3
#
# [1161] Maximum Level Sum of a Binary Tree
#

# Definition for a binary tree node.
from typing import Optional
from collections import deque


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


# @lc code=start
class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        qe = deque()
        qe.append((root, 1))
        arr = []
        while qe:
            node, level = qe.popleft()
            if node:
                if level > len(arr):
                    arr.append(0)
                arr[-1] += node.val
                qe.append((node.left, level + 1))
                qe.append((node.right, level + 1))

        return arr.index(max(arr)) + 1


# @lc code=end
