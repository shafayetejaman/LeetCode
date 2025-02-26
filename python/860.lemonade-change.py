#
# @lc app=leetcode id=860 lang=python3
#
# [860] Lemonade Change
#

# @lc code=start
from typing import List


class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:

        cashBox = [[20, 0], [10, 0], [5, 0]]

        for bill in bills:
            change = list(filter(lambda x: x[0] == bill, cashBox))[0]
            change[1] += 1
            own = bill - 5

            if own:
                for money in cashBox:

                    if money[1] and money[0] <= own:
                        need = own // money[0]
                        canGive = min(need, money[1])
                        own -= money[0] * canGive
                        money[1] -= canGive

            if own > 0:
                return False

        return True


# @lc code=end
