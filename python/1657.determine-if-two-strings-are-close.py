#
# @lc app=leetcode id=1657 lang=python3
#
# [1657] Determine if Two Strings Are Close
#
from collections import Counter


# @lc code=start
class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        d1 = Counter(word1)
        d2 = Counter(word2)

        return sorted(d1.values()) == sorted(d2.values()) and sorted(d1.keys()) == sorted(d2.keys())


# @lc code=end
