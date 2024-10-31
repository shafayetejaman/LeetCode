#
# @lc app=leetcode id=79 lang=python3
#
# [79] Word Search
#


# @lc code=start
class Solution:

    def exist(self, board: list[list[str]], word: str) -> bool:
        n, m = len(board), len(board[0])
        visited: list[list[bool]] = [[False] * m for _ in range(n)]

        def function(r: int, c: int, i: int) -> bool:
            if visited[r][c]:
                return False

            if i + 1 == len(word) and word[i] == board[r][c]:
                return True

            visited[r][c] = True
            curr = False

            if r > 0 and board[r - 1][c] == word[i + 1]:
                curr |= function(r - 1, c, i + 1)

            if r + 1 < n and board[r + 1][c] == word[i + 1]:
                curr |= function(r + 1, c, i + 1)

            if c > 0 and board[r][c - 1] == word[i + 1]:
                curr |= function(r, c - 1, i + 1)

            if c + 1 < m and board[r][c + 1] == word[i + 1]:
                curr |= function(r, c + 1, i + 1)

            visited[r][c] = False

            return curr

        ans = False

        for i in range(n):
            for j in range(m):
                if board[i][j] == word[0]:
                    ans |= function(i, j, 0)

        return ans


# @lc code=end
