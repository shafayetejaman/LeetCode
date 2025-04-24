#
# @lc app=leetcode id=1493 lang=python3
#
# [1493] Longest Subarray of 1's After Deleting One Element
#


# @lc code=start
class Solution:
    def longestSubarray(self, nums: list[int]) -> int:
        k = 1
        ans = l = cnt = 0

        for r in range(len(nums)):
            if nums[r] == 0:
                cnt += 1

            while cnt > k:
                if nums[l] == 0:
                    cnt -= 1

                l += 1
            ans = max(ans, r - l + 1 - cnt)

        return min(ans, len(nums) - 1)


# @lc code=end
