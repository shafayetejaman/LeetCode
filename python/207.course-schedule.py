#
# @lc app=leetcode id=207 lang=python3
#
# [207] Course Schedule
#

# @lc code=start
from typing import List


class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adjList = {pre[0]: [] for pre in prerequisites}
        for sub, pre in prerequisites:
            adjList[sub].append(pre)

        visited = set()

        def dfs(u):
            nonlocal adjList, visited
            if u not in adjList:
                return True

            if u in visited:
                return False

            visited.add(u)

            for v in adjList[u]:
                if not dfs(v):
                    return False

            adjList.pop(u)

            return True

        for pre in prerequisites:
            if pre[0] not in visited and not dfs(pre[0]):
                return False

        return True


# @lc code=end

s = Solution()
print(s.canFinish(2, [[1, 0], [0, 1]]))
