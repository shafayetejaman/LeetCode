#
# @lc app=leetcode id=50 lang=python3
#
# [50] Pow(x, n)
#


# @lc code=start
class Solution:
    def myPow(self, x: float, n: int) -> float:

        if x == 0:
            return 0

        def dfs(n):
            nonlocal x

            if n == 0:
                return 1

            res = dfs(n // 2)
            return res * res if n % 2 == 0 else x * res * res

        res = dfs(abs(n))
        return res if n > -1 else 1 / res


# @lc code=end
