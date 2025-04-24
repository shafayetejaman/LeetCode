#
# @lc app=leetcode id=199 lang=python3
#
# [199] Binary Tree Right Side View
#


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


from typing import List, Optional

# @lc code=start


class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        ans = []

        def bfs(node, level):
            nonlocal ans
            if not node:
                return

            if level == len(ans):
                ans.append(node.val)

            bfs(node.right, level + 1)
            bfs(node.left, level + 1)

        bfs(root, 0)
        return ans


# @lc code=end
