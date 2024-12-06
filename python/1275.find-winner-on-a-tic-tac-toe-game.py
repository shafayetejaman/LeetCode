#
# @lc app=leetcode id=1275 lang=python3
#
# [1275] Find Winner on a Tic Tac Toe Game
#

# @lc code=start
from typing import List


class Solution:
    def tictactoe(self, moves: List[List[int]]) -> str:
        board = [["0"] * 3 for _ in range(3)]

        for i, v in enumerate(moves):
            if i % 2 == 0:
                board[v[0]][v[1]] = "x"
            else:
                board[v[0]][v[1]] = "o"

        for i in range(3):
            if all(board[i][j] == "x" for j in range(3)) or all(
                board[j][i] == "x" for j in range(3)
            ):
                return "A"
            if all(board[i][j] == "o" for j in range(3)) or all(
                board[j][i] == "o" for j in range(3)
            ):
                return "B"

        if all(board[i][i] == "x" for i in range(3)) or all(
            board[i][2 - i] == "x" for i in range(3)
        ):
            return "A"

        if all(board[i][i] == "o" for i in range(3)) or all(
            board[i][2 - i] == "o" for i in range(3)
        ):
            return "B"



        return "Pending" if len(moves) < 9 else "Draw"


# @lc code=end
s = Solution()
print(s.tictactoe([[]]))
