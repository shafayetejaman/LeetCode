#
# @lc app=leetcode id=1004 lang=python3
#
# [1004] max consecutive ones iii
#

# @lc code=start
from typing import List


class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        l = ans = cnt = 0

        for r in range(len(nums)):
            if nums[r] == 0:
                cnt += 1
            while cnt > k:
                if nums[l] == 0:
                    cnt -= 1
                l += 1
            ans = max(ans, r - l + 1)
        return ans


# @lc code=end
s = Solution()
print(s.longestOnes([0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1], 3))
