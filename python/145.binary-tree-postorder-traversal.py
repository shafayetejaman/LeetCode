#
# @lc app=leetcode id=145 lang=python
#
# [145] Binary Tree Postorder Traversal
#


# @lc code=start
# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def postorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if not root:
            return []
        
        if not root.left and root.right:
            return [root.val]

        curr = [root.val]
        left = self.postorderTraversal(root=root.left)
        right = self.postorderTraversal(root=root.right)
        return left + right + curr


# @lc code=end
