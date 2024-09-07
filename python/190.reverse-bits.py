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
        s = str(n)[::-1]
        print(f"{s=} {n=}")
        return int(n)



# @lc code=end
