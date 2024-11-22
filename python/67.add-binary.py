#
# @lc app=leetcode id=67 lang=python3
#
# [67] Add Binary
#


# @lc code=start
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        ans = ""

        i = len(a) - 1
        j = len(b) - 1
        carry = 0

        while i >= 0 and j >= 0:
            sum = int(a[i]) + int(b[j]) + carry
            ans += str(sum % 2)
            carry = sum // 2
            i -= 1
            j -= 1

        while i >= 0:
            sum = int(a[i]) + carry
            ans += str(sum % 2)
            carry = sum // 2
            i -= 1

        while j >= 0:
            sum = int(b[j]) + carry
            ans += str(sum % 2)
            carry = sum // 2
            j -= 1

        if carry:
            ans += str(carry)

        return ans[::-1]


# @lc code=end
