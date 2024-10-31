#
# @lc app=leetcode id=383 lang=python3
#
# [383] Ransom Note
#

# @lc code=start

from collections import Counter


class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        dict1 = Counter(ransomNote)
        dict2 = Counter(magazine)

        for val, cnt in dict1.items():
            if not (dict2.get(val) and dict2[val] >= cnt):
                return False

        return True


# @lc code=end
