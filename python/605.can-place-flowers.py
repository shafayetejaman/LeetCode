#
# @lc app=leetcode id=605 lang=python3
#
# [605] Can Place Flowers
#
from typing import List


# @lc code=start
class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        if len(flowerbed) == 1 and flowerbed[0] == 0:
            return True
        
        if flowerbed[0] == 0 and flowerbed[1] == 0:
            flowerbed[0] = 1
            n -= 1

        if flowerbed[-1] == 0 and flowerbed[-2] == 0:
            flowerbed[-1] = 1
            n -= 1
            
        for i in range(1, len(flowerbed) - 1):
            print(i)
            if flowerbed[i] == 0 and flowerbed[i - 1] == 0 and flowerbed[i + 1] == 0:
                flowerbed[i] = 1
                n -= 1

        return n <= 0


# @lc code=end

s = Solution()
print(s.canPlaceFlowers([1, 0, 1, 0, 1, 0, 1], 1))
