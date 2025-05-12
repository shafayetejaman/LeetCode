#
# @lc app=leetcode id=875 lang=python3
#
# [875] Koko Eating Bananas
#

from typing import List
import math

# @lc code=start


class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l = 1
        r = max(piles)
        ans = 0
        while l <= r:
            m = l + (r - l) // 2
            cnt = 0
            for i in piles:
                cnt += math.ceil(i / m)
            if cnt > h:
                l = m + 1
            else:
                r = m - 1
                ans = m

        return ans


# @lc code=end
s = Solution()
print(s.minEatingSpeed([30, 11, 23, 4, 20], 5))
