#
# @lc app=leetcode id=2206 lang=python3
#
# [2206] Divide Array Into Equal Pairs
#

# @lc code=start
from typing import List
from collections import Counter


class Solution:
    def divideArray(self, nums: List[int]) -> bool:
        cnt = Counter(nums)
        for n in cnt.values():
            if n % 2 == 1:
                return False
        return True


# @lc code=end
