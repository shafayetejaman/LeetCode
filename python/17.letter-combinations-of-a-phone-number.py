#
# @lc app=leetcode id=17 lang=python3
#
# [17] Letter Combinations of a Phone Number
#

# @lc code=start
from typing import List


class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        nums = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "pqrs",
            "8": "tuv",
            "9": "wxyz",
        }
        ans = []

        def fun(i, curr):
            nonlocal nums
            if i == len(digits):
                ans.append(curr)
                return

            for c in nums[digits[i]]:
                fun(i + 1, curr + c)

        fun(0, "")
        return ans if digits else []


# @lc code=end
