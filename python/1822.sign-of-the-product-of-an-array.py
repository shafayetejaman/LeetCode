#
# @lc app=leetcode id=1822 lang=python3
#
# [1822] Sign of the Product of an Array
#

# @lc code=start
from typing import List


class Solution:
    def arraySign(self, nums: List[int]) -> int:
        minus =0
        for i in nums:
            if i == 0:
                return 0
            elif i < 0:
                minus += 1
            
        return -1 if minus % 2 == 1 else 1
    
# @lc code=end

