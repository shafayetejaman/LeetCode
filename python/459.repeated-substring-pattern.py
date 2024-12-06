#
# @lc app=leetcode id=459 lang=python3
#
# [459] Repeated Substring Pattern
#


# @lc code=start
class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:

        for i in range(len(s) // 2):
            sub = s[: i + 1]
            # print(f"{sub=}")
            for j in range(i + 1, len(s)):
                # print(f"{j=} {sub[j % len(sub)] =}")
                if sub[j % len(sub)] != s[j]:
                    break
                if j == len(s) - 1 and j % len(sub) == len(sub) - 1:
                    return True

        return False


# @lc code=end

s = Solution()
s.repeatedSubstringPattern("aabaaba")
