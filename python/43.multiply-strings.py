#
# @lc app=leetcode id=43 lang=python
#
# [43] Multiply Strings
#


# @lc code=start
class Solution:
    def multiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        _list = []
        zero = 1
        # Fix range to iterate from the end to the start
        for i in range(len(num2) - 1, -1, -1):
            i_digit = int(num2[i])
            it = 1
            num = 0
            c = 0
            for j in range(len(num1) - 1, -1, -1):
                j_digit = int(num1[j])
                num += ((j_digit * i_digit + c) % 10) * it
                c = (j_digit * i_digit + c) // 10
                it *= 10
            if c > 0:  # Add any remaining carry
                num += c * it
            _list.append(num * zero)
            zero *= 10

        return str(sum(_list))


print(Solution().multiply("50", "60"))

# @lc code=end
