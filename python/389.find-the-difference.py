#
# @lc app=leetcode id=389 lang=python3
#
# [389] Find the Difference
#


# @lc code=start
# from collections import Counter


# class Solution:
#     def findTheDifference(self, s: str, t: str):
#         m = Counter(s)

#         for i in t:
#             if m[i] == 0:
#                 return i
#             m[i] -= 1


class Solution:
    def findTheDifference(self, s: str, t: str):
        sum = 0
    
        for i in s:
            sum -= ord(i)

        for i in t:
            sum += ord(i)
            
        return chr(sum)

# @lc code=end
