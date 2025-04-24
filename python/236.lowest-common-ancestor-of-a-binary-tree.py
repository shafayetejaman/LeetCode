#
# @lc app=leetcode id=236 lang=python3
#
# [236] Lowest Common Ancestor of a Binary Tree
#


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


# class Solution:
#     def lowestCommonAncestor(
#         self, root: TreeNode, p: TreeNode, q: TreeNode
#     ) -> TreeNode:

#         def dfs(root, curr, val):
#             if not root:
#                 return []
#             curr.append(root)
#             if root.val == val:
#                 return curr

#             left = dfs(root.left, curr.copy(), val)
#             right = dfs(root.right, curr.copy(), val)

#             return left + right

#         l1 = dfs(root, [], p.val)
#         l2 = dfs(root, [], q.val)

#         i = 0
#         while i < min(len(l1), len(l2)) and l1[i] == l2[i]:
#             i += 1

#         return l1[i - 1]

# @lc code=start


class Solution:
    def lowestCommonAncestor(
        self, root: TreeNode, p: TreeNode, q: TreeNode
    ) -> TreeNode | None:

        if not root:
            return None

        if root == q or root == p:
            return root

        left = self.lowestCommonAncestor(root.left, p, q)
        right = self.lowestCommonAncestor(root.right, p, q)

        if left and right:
            return root

        return left if left else right


# @lc code=end
