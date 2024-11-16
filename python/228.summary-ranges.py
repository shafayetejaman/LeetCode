#
# @lc app=leetcode id=228 lang=python3
#
# [228] Summary Ranges
#


# @lc code=start
from typing import List


class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        if len(nums) <= 1:
            return list(map(str, nums))

        ans: list[str] = []
        prev: List[int] = [0, nums[0]]

        i = 0

        while i < len(nums) - 1:
            if nums[i + 1] - nums[i] != 1:
                if abs(prev[0] - i) >= 1:
                    ans.append(f"{prev[1]}->{nums[i]}")
                else:
                    ans.append(str(nums[i]))
                prev[0], prev[1] = i + 1, nums[i + 1]

            i += 1

        if abs(prev[0] - i) >= 1:
            ans.append(f"{prev[1]}->{nums[i]}")
        else:
            ans.append(str(nums[i]))

        return ans


# @lc code=end

s = Solution()
print(s.summaryRanges([0, 1, 2, 5, 6, 7]))
