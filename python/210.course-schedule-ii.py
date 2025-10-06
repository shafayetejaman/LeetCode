#
# @lc app=leetcode id=210 lang=python3
#
# [210] Course Schedule II
#

# @lc code=start
from typing import List


class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        adjList = {pre[0]: [] for pre in prerequisites}
        for sub, pre in prerequisites:
            adjList[sub].append(pre)

        visited = set()
        ans = []

        def dfs(u):
            nonlocal adjList, visited, ans
            if u not in adjList:
                return True

            if u in visited:
                return False

            visited.add(u)

            for v in adjList[u]:
                if not dfs(v):
                    return False

            adjList.pop(u)
            ans.append(u)

            return True

        for pre in prerequisites:
            if pre[0] not in visited and not dfs(pre[0]):
                return []

        return ans


# @lc code=end
