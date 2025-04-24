#
# @lc app=leetcode id=345 lang=python3
#
# [345] Reverse Vowels of a String
#


# @lc code=start
class Solution:
    def reverseVowels(self, s: str) -> str:
        vowels = "aeiouAEIOU"
        v = []
        ans = []
        for i in s:
            if i in vowels:
                v.append(i)

        j = 0
        n = len(v)
        for i in range(len(s)):
            if j < n and v[j] == s[i]:
                ans.append(v[n - j - 1])
                j += 1
            else:
                ans.append(s[i])

        return "".join(ans)


# @lc code=end

s = Solution()
print(s.reverseVowels("IceCreAm"))
