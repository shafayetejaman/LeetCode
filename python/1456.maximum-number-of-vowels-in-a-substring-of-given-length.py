#
# @lc app=leetcode id=1456 lang=python3
#
# [1456] Maximum Number of Vowels in a Substring of Given Length
#


# @lc code=start
class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        l = cnt = ans = 0
        vowels = "aeiou"

        for r in range(len(s)):
            if s[r] in vowels:
                cnt += 1
            if r - l + 1 > k:
                if s[l] in vowels:
                    cnt -= 1
                l += 1
            if r - l + 1 == k:
                ans = max(ans, cnt)

        return ans


# @lc code=end
s = Solution()
print(s.maxVowels("abciiidef", 3))
