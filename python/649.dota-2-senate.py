#
# @lc app=leetcode id=649 lang=python3
#
# [649] Dota2 Senate
#

from collections import deque

# @lc code=start


class Solution:
    def predictPartyVictory(self, senate: str) -> str:
        dqr = deque()
        dqd = deque()
        n = len(senate)

        for idx, val in enumerate(senate):
            if val == "R":
                dqr.append(idx)
            else:
                dqd.append(idx)

        while dqr and dqd:
            r = dqr.popleft()
            d = dqd.popleft()

            if r < d:
                dqr.append(r + n)
            else:
                dqd.append(d + n)

        return "Dire" if dqd else "Radiant"


# @lc code=end
s = Solution()
print(s.predictPartyVictory("RDD"))
