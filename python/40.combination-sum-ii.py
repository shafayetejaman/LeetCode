#
# @lc app=leetcode id=40 lang=python
#
# [40] Combination Sum II
#


# @lc code=start
class Solution(object):
    def combinationSum2(self, candidates: list[int], target: int) -> list[list[int]]:
        ans: list[list[int]] = []
        candidates.sort()

        def fun(i: int, sum: int, curr: list[int]):
            if sum == target:
                ans.append(curr.copy())
                return

            if sum > target or i >= len(candidates):
                return

            curr.append(candidates[i])
            sum += candidates[i]
            fun(i + 1, sum=sum, curr=curr)

            curr.pop()
            sum -= candidates[i]

            while i < len(candidates) - 1 and candidates[i] == candidates[i + 1]:
                i += 1

            fun(i + 1, sum=sum, curr=curr)

        fun(0, 0, curr=[])

        return ans


# @lc code=end
