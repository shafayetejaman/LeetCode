"""
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
"""


# 13. Roman to Integer
class Solution:
    def romanToInt(self, s: str) -> int:
        m = {}
        m["I"] = 1
        m["V"] = 5
        m["X"] = 10
        m["L"] = 50
        m["C"] = 100
        m["D"] = 500
        m["M"] = 1000

        _sum = 0
        i = 0
        while i < len(s) - 1:
            if m[s[i]] < m[s[i + 1]]:
                _sum += m[s[i + 1]] - m[s[i]]
                i += 1
            else:
                _sum += m[s[i]]
            i += 1

        if i < len(s):
            _sum += m[s[i]]

        return _sum


# 414. Third Maximum Number


class Solution:
    def thirdMax(self, nums) -> int:
        nums = set(nums)

        if len(nums) < 3:
            return max(nums)

        nums.remove(max(nums))
        nums.remove(max(nums))

        return max(nums)


# 1346. Check If N and Its Double Exist


class Solution:
    def checkIfExist(self, arr) -> bool:
        se = set()

        for i in arr:
            se.add(i)

        for i in se:
            if i != 0 and i * 2 in se:
                return True

        return False
