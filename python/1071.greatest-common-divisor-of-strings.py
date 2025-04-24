#
# @lc app=leetcode id=1071 lang=python3
#
# [1071] Greatest Common Divisor of Strings
#
# Input: str1 = "ABABAB", str2 = "ABAB"
# Output: "AB"


# @lc code=start
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        len1, len2 = len(str1), len(str2)

        def isDivisibale(n):
            l1 = len1 // n
            l2 = len2 // n
            s = str1[:n]
            return s * l1 == str1 and s * l2 == str2

        for n in range(min(len1, len2), 0, -1):
            if isDivisibale(n):
                return str1[:n]

        return ""


# @lc code=end
