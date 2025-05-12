#
# @lc app=leetcode id=162 lang=python3
#
# [162] Find Peak Element
#

from typing import List

# @lc code=start


class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        N = len(nums)
        l, r = 0, N - 1

        while l <= r:
            m = l + (r - l) // 2
            if 0 < m and nums[m - 1] > nums[m]:
                r = m - 1
            elif m < N - 1 and nums[m] < nums[m + 1]:
                l = m + 1
            else:
                return m

        return 0


# @lc code=end
