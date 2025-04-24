#
# @lc app=leetcode id=1679 lang=python3
#
# [1679] Max Number of K-Sum Pairs
#
from collections import defaultdict


# @lc code=start
class Solution:
    def maxOperations(self, nums: list[int], k: int) -> int:
        d = defaultdict(int)
        ans = 0

        for i in nums:
            n = k - i
            if d[n] > 0:
                ans += 1
                d[n] -= 1
            else:
                d[i] += 1

        return ans


# @lc code=end
