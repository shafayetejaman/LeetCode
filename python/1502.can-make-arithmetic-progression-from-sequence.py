#
# @lc app=leetcode id=1502 lang=python3
#
# [1502] Can Make Arithmetic Progression From Sequence
#

# @lc code=start
from typing import List


class Solution:
    def canMakeArithmeticProgression(self, arr: List[int]) -> bool:
        arr.sort()
        diff = abs(arr[0] - arr[1])
        # print(arr)
        for i in range(1, len(arr) - 1):
            if diff != abs(arr[i] - arr[i + 1]):
                # print(idx, val, abs(val - arr[idx + 1]))
                return False

        return True


# @lc code=end
