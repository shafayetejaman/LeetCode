#
# @lc app=leetcode id=66 lang=python
#
# [66] Plus One
#


# @lc code=start
class Solution(object):

    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        carry = 1
        idx = len(digits) - 1

        while carry and idx > -1:
            digits[idx] += carry
            carry = digits[idx] // 10
            digits[idx] = digits[idx] % 10
            idx -= 1

        if carry:
            digits.insert(0, 1)


        return digits


# @lc code=end
