#
# @lc app=leetcode id=394 lang=python3
#
# [394] Decode String
#


# @lc code=start
class Solution:
    def decodeString(self, s: str) -> str:
        st = []
        for i in s:
            if i == "]":
                sub = []
                num = 0
                n = 1
                while st[-1] != "[":
                    sub.append(st.pop())
                st.pop()
                while st and st[-1].isnumeric():
                    num += n * int(st.pop())
                    n *= 10
                st.append(num * "".join(reversed(sub)))
            else:
                st.append(i)

        return "".join(st)


# @lc code=end
s = Solution()
print(s.decodeString("2[abc]3[cd]ef"))
