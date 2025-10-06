<<<<<<< HEAD
from collections import deque
from typing import Deque, Tuple


class Node:
    def __init__(self, val, left=None, right=None) -> None:
        self.val = val
        self.left = left
        self.right = right


def bfs(root: Node | None, predecessor: dict):
    if not root:
        return []

    queue: Deque[Tuple[Node, int]] = deque()
    queue.append((root, 1))
    predecessor[root] = (None, None)

    nodeList = []

    while queue:
        parent, level = queue.popleft()

        if len(nodeList) < level:
            nodeList.append([])

        nodeList[level - 1].append(parent)

        leftChild = parent.left
        rightChild = parent.right

        if leftChild:
            queue.append((leftChild, level + 1))
            predecessor[leftChild] = (
                parent,
                predecessor.get(parent, (None, None))[0],
            )

        if rightChild:
            queue.append((rightChild, level + 1))
            predecessor[rightChild] = (
                parent,
                predecessor.get(parent, (None, None))[0],
            )
    return nodeList


# build the tree from input
def build_tree(inputs: list):
    if not inputs:
        return None

    root = Node(inputs[0])
    queue = [root]
    i = 1

    while i < len(inputs):
        current = queue.pop(0)

        # Left child
        if i < len(inputs) and inputs[i] != -1:
            current.left = Node(inputs[i])
            queue.append(current.left)
        i += 1

        # Right child
        if i < len(inputs) and inputs[i] != -1:
            current.right = Node(inputs[i])
            queue.append(current.right)
        i += 1

    return root


# Example usage
inputs = [1, 2, 3, 4, 5, -1, 6, -1, -1, -1, -1, -1, -1]
root = build_tree(inputs)
predecessor = {}
nodeList = bfs(root, predecessor)
# Print predecessor
for node, (parent, grandparent) in predecessor.items():
    p_val = parent.val if parent else None
    gp_val = grandparent.val if grandparent else None
    print(f"Node: {node.val}, Parent: {p_val}, Grandparent: {gp_val}")

# Print nodeList
for level, nodes in enumerate(nodeList):
    print(f"Level {level+1}: {[node.val for node in nodes]}")


for nodes in nodeList:
    for node in nodes:
        cnt = 0
        parentOfNode, grandparentOfNode = predecessor[node]
        for cousin in nodes:
            if cousin == node:
                continue
            parentOfCousin, grandparentOfCousin = predecessor[cousin]

            if (
                grandparentOfNode == grandparentOfCousin
                and parentOfNode != parentOfCousin
            ):
                cnt += 1

        print(cnt, end=" ")
print()
=======
class Solution:
    def isValid(self, s: str):
        st = []
        for char in s:
            if char == "(":
                st.append("(")
            elif not st:
                return False
            else:
                st.pop()
        return len(st) == 0

    def generateParenthesis(self, n: int) -> list[str]:
        ans: list[str] = []

        def dfs(s):
            nonlocal ans
            if len(s) == 2 * n:
                if self.isValid(s):
                    ans.append(s)

                return

            dfs(s + "(")
            dfs(s + ")")

        dfs("")

        return ans

>>>>>>> 104da0f5dc1d28d71749e751177791d69b086fd3
