#
# @lc app=leetcode id=2300 lang=python3
#
# [2300] Successful Pairs of Spells and Potions
#

from typing import List

# @lc code=start


class Solution:
    def successfulPairs(
        self, spells: List[int], potions: List[int], success: int
    ) -> List[int]:
        potions.sort()
        n, k = len(spells), len(potions)
        ans = [0] * len(spells)

        for i in range(n):
            last = k
            l, r = 0, k - 1 
            while l <= r:
                m = l + (r - l) // 2
                p = potions[m] * spells[i]
              
                if p >= success:
                    r = m - 1
                    last = m
                else:
                    l = m + 1

            ans[i] = k - last

        return ans


# @lc code=end

s = Solution()
print(s.successfulPairs([5, 1, 3], [1, 2, 3, 4, 5], 7))
