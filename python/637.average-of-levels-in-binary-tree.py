#
# @lc app=leetcode id=637 lang=python3
#
# [637] Average of Levels in Binary Tree
#

from collections import deque
from typing import List, Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


# @lc code=start
# Definition for a binary tree node.



class Solution:
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:

        return self.bfs(root)

    def bfs(self, root: Optional[TreeNode]):
        level = 1
        q = deque()
        q.append([level, root])
        ans = []
        avg = 0
        div = 0

        while q:
            curr = q.popleft()

            if level < curr[0]:
                ans.append(avg / div)
                avg = curr[1].val
                div = 1
                level = curr[0]
            else:
                avg += curr[1].val
                div += 1

            if curr[1].left:
                q.append([curr[0] + 1, curr[1].left])
            if curr[1].right:
                q.append([curr[0] + 1, curr[1].right])

        ans.append(avg / div)
        return ans


# @lc code=end
