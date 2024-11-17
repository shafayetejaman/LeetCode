#
# @lc app=leetcode id=222 lang=python3
#
# [222] Count Complete Tree Nodes
#


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


# @lc code=start
class Solution:
    def countNodes(self, root: TreeNode | None) -> int:
        if not root:
            return 0

        left = self.rightCount(root)
        right = self.leftCount(root)

        if left == right:
            return 2**left - 1
        else:
            return self.countNodes(root.left) + self.countNodes(root.right) + 1

    def rightCount(self, root):
        cnt = 0
        while root:
            root = root.right
            cnt += 1

        return cnt

    def leftCount(self, root):
        cnt = 0
        while root:
            root = root.left
            cnt += 1

        return cnt


# @lc code=end
