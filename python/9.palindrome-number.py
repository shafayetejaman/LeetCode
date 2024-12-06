#
# @lc app=leetcode id=9 lang=python3
#
# [9] Palindrome Number
#


# @lc code=start
class Solution:
    def isPalindrome(self, x: int) -> bool:

        t = x
        stack = []

        if x < 0:
            return False

        while t:
            stack.append(t % 10)
            t //= 10

        n = len(stack) // 2

        print(f"{n}")
        for _ in range(n):
            if x % 10 != stack.pop():

                return False
            x //= 10

        return True


# @lc code=end
s = Solution()
s.isPalindrome(121)
