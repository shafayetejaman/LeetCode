#
# @lc app=leetcode id=190 lang=python
#
# [190] Reverse Bits
#


# @lc code=start
class Solution:
    # @param n, an integer
    # @return an integer
    def reverseBits(self, n: int) -> int:
        ans = 0
        for i in range(32):
            if n & 1:
                ans |= 1 << (31 - i)
            n >>= 1
        return ans


# @lc code=end
