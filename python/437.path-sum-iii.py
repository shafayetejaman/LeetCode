#
# @lc app=leetcode id=437 lang=python3
#
# [437] Path Sum III
#
# Definition for a binary tree node.
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


# class Solution:

#     def calSum(self, root: Optional[TreeNode], targetSum) -> int:
#         if not root:
#             return 0
#         cnt = 0
#         if targetSum == root.val:
#             cnt += 1
#         targetSum -= root.val
#         cnt += self.calSum(root.left, targetSum)
#         cnt += self.calSum(root.right, targetSum)
#         return cnt

#     def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
#         if not root:
#             return 0

#         return (
#             self.calSum(root, targetSum)
#             + self.pathSum(root.left, targetSum)
#             + self.pathSum(root.right, targetSum)
#         )

from collections import defaultdict

# @lc code=start


class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        if not root:
            return 0
        cache = defaultdict(int)
        cnt = 0

        def count(root, currentSum):
            nonlocal cnt, cache

            if not root:
                return

            currentSum += root.val
            cnt += cache[currentSum - targetSum]
            cache[currentSum] += 1

            count(root.left, currentSum)
            count(root.right, currentSum)

            cache[currentSum] -= 1

        cache[0] = 1
        count(root, 0)
        return cnt


# @lc code=end
