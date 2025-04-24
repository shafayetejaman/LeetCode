#
# @lc app=leetcode id=1732 lang=python3
#
# [1732] Find the Highest Altitude
#

# @lc code=start
from typing import List


class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        max_gain = 0
        curr_gain = 0
        for i in gain:
            curr_gain += i
            max_gain = max(max_gain, curr_gain)

        return max_gain

# @lc code=end
