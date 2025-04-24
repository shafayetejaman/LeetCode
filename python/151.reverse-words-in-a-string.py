#
# @lc app=leetcode id=151 lang=python3
#
# [151] Reverse Words in a String
#


# @lc code=start
# class Solution:
#     def reverseWords(self, s: str) -> str:
#         l = 0
#         n = len(s)
#         st = []
#         while l < n and s[l] == " ":
#             l += 1

#         while l < n:
#             r = l
#             while r < n - 1 and s[r + 1] != " ":
#                 r += 1
#             st.append(s[l : r + 1])
#             l = r + 1
#             while l < n and s[l] == " ":
#                 l += 1
#         # print(st)
#         return " ".join(st[::-1])


class Solution:
    def reverseWords(self, s) -> str:
        s = list(s)
        n = len(s)
        read = write = 0

        while read < n - 1:
            if s[read] == " " and write == 0:
                read += 1
                continue
            if (s[read] == " " and s[read + 1] != " ") or s[read] != " ":
                s[write] = s[read]
                write += 1
            read += 1

        s[write] = s[read]

        while len(s) > write + 1 or s[-1] == " ":
            s.pop()

        s.reverse()
        l = r = 0
        n = len(s)
        while r < n - 1:
            if s[r + 1] == " ":
                self.reverse(s, l, r)
                l = r + 2
            r += 1

        self.reverse(s, l, r)
        return "".join(s)

    def reverse(self, arr, l, r):
        while l < r:
            arr[l], arr[r] = arr[r], arr[l]
            l += 1
            r -= 1


# @lc code=end

s = Solution()
print(s.reverseWords("  hello world  "))
