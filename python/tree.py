# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from queue import LifoQueue as stacks


class Solution:
    def kthSmallest(self, root, k: int) -> int:
        stack = stacks()
        node = root

        while True:
            while node:
                stack.put(node)
                node = node.left

            node = stack.get()
            k -= 1

            if not k:
                return node.val

            node = node.right


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def buildTree(self, preorder, inorder):
        if not preorder or not inorder:
            return None

        root = TreeNode(preorder[0])
        mid = inorder.index(root.val)

        root.left = self.buildTree(preorder[1 : mid + 1], inorder[:mid])
        root.right = self.buildTree(preorder[mid + 1 :], inorder[mid + 1 :])

        return root


class Node:
    def __init__(self) -> None:
        self.char = {}
        self.end = False


class Trie:
    def __init__(self):
        self.root = Node()

    def insert(self, word: str) -> None:
        curr = self.root

        for c in word:
            if c not in curr.char:
                curr.char[c] = Node()

            curr = curr.char[c]

        curr.end = True

    def search(self, word: str) -> bool:
        curr = self.root

        for c in word:
            if c not in curr.char:
                return False

            curr = curr.char[c]

        return curr.end

    def startsWith(self, prefix: str) -> bool:
        curr = self.root

        for c in prefix:
            if c not in curr.char:
                return False

            curr = curr.char[c]

        return True


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)


class Node:
    def __init__(self) -> None:
        self.char = {}
        self.end = False


class WordDictionary:
    def __init__(self):
        self.root = Node()

    def addWord(self, word: str) -> None:
        curr = self.root

        for c in word:
            if c not in curr.char:
                curr.char[c] = Node()

            curr = curr.char[c]

        curr.end = True

    def search(self, word: str) -> bool:

        def fun(idx, curr):
            if idx == len(word):
                return curr.end

            c = word[idx]
            if c == ".":
                for child in curr.char.values():
                    if fun(idx + 1, child):
                        return True
            else:
                if c not in curr.char:
                    return False

                return fun(idx + 1, curr.char[c])

        return fun(0, self.root)


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)


# 257. Binary Tree Paths


class Solution:
    def binaryTreePaths(self, root) -> List[str]:
        path = []
        
        def dfs(root, ):
            
        dfs(root=root,[])
        return path
