#
# @lc app=leetcode id=168 lang=python3
#
# [168] Excel Sheet Column Title
#


# @lc code=start
class Solution:
    def convertToTitle(self, columnNumber: int) -> str:
        ans = ""
        while columnNumber:
            rem = (columnNumber - 1) % 26
            columnNumber = (columnNumber - 1) // 26
            ans += chr(ord("A") + rem)

        return ans[::-1]


# @lc code=end
