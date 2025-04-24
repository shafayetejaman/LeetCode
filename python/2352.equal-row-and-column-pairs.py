#
# @lc app=leetcode id=2352 lang=python3
#
# [2352] Equal Row and Column Pairs
#

# @lc code=start
from typing import List
from collections import defaultdict


class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        d = defaultdict(int)
        n = len(grid)
        cnt = 0
        for i in grid:
            d[hash(tuple(i))] += 1
        for i in range(n):
            sub_arr = [grid[k][i] for k in range(n)]
            j = hash(tuple(sub_arr))
            if j in d:
                cnt += d[j]
        return cnt


# @lc code=end
s = Solution()
print(s.equalPairs([[3, 1, 2, 2], [1, 4, 4, 5], [2, 4, 2, 2], [2, 4, 2, 2]]))
