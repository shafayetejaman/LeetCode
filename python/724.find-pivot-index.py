#
# @lc app=leetcode id=724 lang=python3
#
# [724] Find Pivot Index
#


# @lc code=start
from typing import List


class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        n = len(nums)
        sub = [0] * (n + 1)

        for i in range(n - 1, 0, -1):
            sub[i] = nums[i] + sub[i + 1]

        sum = 0
        for i in range(n):
            if sum == sub[i + 1]:
                return i
            sum += nums[i]
        return -1


# @lc code=end
s = Solution()
print(s.pivotIndex([1, 7, 3, 6, 5, 6]))
