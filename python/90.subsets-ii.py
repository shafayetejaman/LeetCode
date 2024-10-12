#
# @lc app=leetcode id=90 lang=python
#
# [90] Subsets II
#


# @lc code=start
class Solution(object):
    def subsetsWithDup(self, nums: list):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        ans: list[list[str]] = []
        nums.sort()

        def fun(i: int, curr: list[str]) -> None:
            if i >= len(nums):
                ans.append(curr.copy())
                return

            curr.append(nums[i])
            fun(i + 1, curr=curr)
            curr.pop()

            while i < len(nums) - 1 and nums[i] == nums[i + 1]:
                i += 1

            fun(i + 1, curr=curr)

        fun(0, [])
        return ans


# @lc code=end
