#
# @lc app=leetcode id=171 lang=python3
#
# [171] Excel Sheet Column Number
#


# @lc code=start
class Solution:
    def titleToNumber(self, columnTitle: str) -> int:
        p = 0
        ans = 0

        for c in columnTitle[::-1]:
            num = ord(c) - 64
            ans += num * pow(26, p)
            p += 1

        return ans


# @lc code=end

s = Solution()
print(s.titleToNumber("ZY"))
