#
# @lc app=leetcode id=976 lang=python3
#
# [976] Largest Perimeter Triangle
#

# @lc code=start
from typing import List


class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        n = len(nums)
        i, j, k = n - 3, n - 2, n - 1
        nums.sort()
        while i >= 0:
            if nums[i] + nums[j] > nums[k]:
                return nums[i] + nums[j] + nums[k]
            i -= 1
            j -= 1
            k -= 1
        return 0


# @lc code=end
