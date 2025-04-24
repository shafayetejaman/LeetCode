#
# @lc app=leetcode id=443 lang=python3
#
# [443] String Compression
#


# @lc code=start
class Solution:
    def compress(self, chars: list[str]) -> int:
        c: str = chars[0]
        cnt = 1
        j = 0

        for i in range(1, len(chars)):
            if c == chars[i]:
                cnt += 1
            else:
                chars[j] = c
                j+=1
                if cnt > 1:
                    for k in str(cnt):
                        chars[j] = k
                        j+=1
                c = chars[i]
                cnt = 1

        chars[j] = c
        j+=1
        if cnt > 1:
            for k in str(cnt):
                chars[j] = k
                j+=1
              

        return j


# @lc code=end

s = Solution()
print(s.compress(["a", "a", "b", "b", "c", "c", "c"]))
