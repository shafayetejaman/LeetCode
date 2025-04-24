#
# @lc app=leetcode id=1372 lang=python3
#
# [1372] Longest ZigZag Path in a Binary Tree
#

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


from typing import Optional

# @lc code=start


class Solution:
    def longestZigZag(self, root: Optional[TreeNode]) -> int:
        ans = 0

        def cal(root, left, curr):
            nonlocal ans
            if not root:
                return

            ans = max(ans, curr)
            if left:
                cal(root.right, False, curr + 1)
                cal(root.left, True, 1)
            else:
                cal(root.right, False, 1)
                cal(root.left, True, curr + 1)

        cal(root.left, True, 1)
        cal(root.right, False, 1)

        return ans


# @lc code=end
