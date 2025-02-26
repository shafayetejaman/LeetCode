#
# @lc app=leetcode id=1672 lang=python3
#
# [1672] Richest Customer Wealth
#

# @lc code=start
from typing import List


class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> int:
        # return sum(max(accounts, key=lambda x: sum(x)))
        ans = 0
        for account in accounts:
            ans = max(ans, sum(account))

        return ans


# @lc code=end
