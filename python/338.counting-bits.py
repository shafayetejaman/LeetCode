#
# @lc app=leetcode id=338 lang=python3
#
# [338] Counting Bits
#
from typing import List


# @lc code=start
# class Solution:
#     def countBits(self, n: int) -> List[int]:
#         arr = [0] * (n + 1)
#         p = 2
#         if n > 0:
#             arr[1] = 1
#         for i in range(2, n + 1):
#             if i == p:
#                 p = 2 * p
#                 arr[i] = 1
#             elif i % 2 == 1:
#                 arr[i] = arr[i - 1] + 1
#             elif i & (i + 1) == i:
#                 arr[i] = bin(i).count("1")
#             else:
#                 arr[i] = arr[i - 1]

#         return arr
class Solution:
    def countBits(self, n: int) -> List[int]:
        arr = [0] * (n + 1)
        p = 1
        for i in range(1,n + 1):
            if 2 * p == i:
                p = i 
                arr[i] = 1
            else:
                arr[i] = 1 + arr[i - p] 
                
        return arr


# @lc code=end
