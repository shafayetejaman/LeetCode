#
# @lc app=leetcode id=896 lang=python3
#
# [896] Monotonic Array
#

# @lc code=start
from typing import List


class Solution:
    def isMonotonic(self, nums: List[int]) -> bool:
        dec = all(nums[i] >= nums[i+1] for i in range(0,len(nums)-1))
        ace = all(nums[i] <= nums[i+1] for i in range(0,len(nums)-1))

        return dec or ace

# @lc code=end

