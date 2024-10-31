#
# @lc app=leetcode id=131 lang=python3
#
# [131] Palindrome Partitioning
#

# @lc code=start
from typing import List


class Solution:
    def is_palindrome(self, s: str, i: int, j: int) -> bool:
        while i < j:
            if s[i] != s[j]:
                return False
            i += 1
            j -= 1

        return True

    def partition(self, s: str) -> List[List[str]]:

        ans: list[list[str]] = []
        part: list[str] = []

        def function(i: int) -> None:
            if i >= len(s):
                ans.append(part.copy())
                return

            for j in range(i, len(s)):
                if self.is_palindrome(s, i, j):
                    part.append(s[i : j + 1])
                    function(j + 1)
                    part.pop()
        function(0)

        return ans


# @lc code=end
