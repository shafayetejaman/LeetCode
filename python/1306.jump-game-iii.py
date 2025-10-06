#
# @lc app=leetcode id=1306 lang=python3
#
# [1306] Jump Game III
#

# @lc code=start
from typing import List


class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        N = len(arr)
        visited = [0] * N

        def dfs(u):
            nonlocal arr, visited

            if u < 0 or u >= N or visited[u]:
                return False

            visited[u] = 1

            if arr[u] == 0:
                return True
            return dfs(u + arr[u]) or dfs(u - arr[u])

        return dfs(start)


# @lc code=end
