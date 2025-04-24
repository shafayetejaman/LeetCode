#
# @lc app=leetcode id=1431 lang=python3
#
# [1431] Kids With the Greatest Number of Candies
#

# @lc code=start
from typing import List


class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int):
        m = max(candies)
        ans = [True]*len(candies)  
        for idx, val in enumerate(candies):
            if val + extraCandies < m:
                ans[idx] = False

        return ans

# @lc code=end
