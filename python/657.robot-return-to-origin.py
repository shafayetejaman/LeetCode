#
# @lc app=leetcode id=657 lang=python3
#
# [657] Robot Return to Origin
#

# @lc code=start
from collections import Counter


class Solution:
    def judgeCircle(self, moves: str) -> bool:
        _dict = Counter(moves)

        u = _dict["U"]
        d = _dict["D"]
        l = _dict["L"]
        r = _dict["R"]

        return u == d and r == l


# @lc code=end

s = Solution()
print(s.judgeCircle("U"))
