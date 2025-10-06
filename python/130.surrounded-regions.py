#
# @lc app=leetcode id=130 lang=python3
#
# [130] Surrounded Regions
#

# @lc code=start
from typing import List


class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        direction = ((1, 0), (0, 1), (-1, 0), (0, -1))
        N, M = len(board), len(board[0])

        def dfs(row, col):
            nonlocal M, N, direction, board

            if (
                row not in range(0, N)
                or col not in range(0, M)
                or board[row][col] != "O"
            ):
                return

            board[row][col] = "T"

            for r, c in direction:
                dfs(row + r, col + c)

        for i in range(N):
            for j in range(M):
                if i in [0, N - 1] or j in [0, M - 1] and board[i][j] == "O":
                    dfs(i, j)
        print(board)
        for i in range(N):
            for j in range(M):
                if board[i][j] == "O":
                    board[i][j] = "X"
                if board[i][j] == "T":
                    board[i][j] = "O"


# @lc code=end

s = Solution()
print(
    s.solve(
        [
            ["X", "X", "X", "X"],
            ["X", "O", "O", "X"],
            ["X", "X", "O", "X"],
            ["X", "O", "X", "X"],
        ]
    )
)
