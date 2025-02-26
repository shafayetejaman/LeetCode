#
# @lc app=leetcode id=1232 lang=python3
#
# [1232] Check If It Is a Straight Line
#
from typing import List


# @lc code=start
class Solution:
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        x1, y1 = coordinates[0]
        x2, y2 = coordinates[1]

        diffX = x1 - x2
        diffY = y1 - y2

        for preIdx, currCoor in enumerate(coordinates, start=-1):
            if preIdx < 1:
                continue

            currDiffX = coordinates[preIdx][0] - currCoor[0]
            currDiffY = coordinates[preIdx][1] - currCoor[1]

            if currDiffX * diffY != diffX * currDiffY:
                return False

        return True


# @lc code=end

s = Solution()
print(s.checkStraightLine([[1, -8], [2, -3], [1, 2]]))
