#
# @lc app=leetcode id=334 lang=python3
#
# [334] Increasing Triplet Subsequence
#
from typing import List

# @lc code=start


class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        inf = float("inf")
        m = m2 = m3 = inf
        for i in nums:
            m = min(m, i)
            if i != m:
                m2 = min(m2, i)
            if i != m2 and i != m:
                m3 = min(m3, i)

            if inf != m and inf != m2 and inf != m3:
                # print(m, m2, m3, sep="\n")
                return True

        return False


# @lc code=end
s = Solution()
print(s.increasingTriplet([2, 4, -2, -3]))
