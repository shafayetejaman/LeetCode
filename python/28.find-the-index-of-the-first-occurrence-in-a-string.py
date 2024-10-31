#
# @lc app=leetcode id=28 lang=python3
#
# [28] Find the Index of the First Occurrence in a String
#


# @lc code=start
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        j = 0

        while j <= len(haystack) - len(needle):
            if haystack[j] != needle[0]:
                j += 1
                continue
            i = 0
            k = j
            while i < len(needle):
                if needle[i] != haystack[k]:
                    break
                if i == len(needle) - 1:
                    return j
                i += 1
                k += 1
            j += 1

        return -1


# @lc code=end
