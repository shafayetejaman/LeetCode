#
# @lc app=leetcode id=205 lang=python3
#
# [205] Isomorphic Strings
#


# @lc code=start
class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        d1 = {}
        d2 = {}

        for i, val in enumerate(s):
            if d1.get(val) and d1[val] != t[i]:
                return False
            elif d2.get(t[i]) and d2[t[i]] != val:
                return False

            d1[val] = t[i]
            d2[t[i]] = val

        return True


# @lc code=end
